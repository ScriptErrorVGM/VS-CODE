from requests_html import HTMLSession
from urllib.parse import urlparse, urljoin
from bs4 import BeautifulSoup
import colorama

import requests
import pandas as pd

import time
from datetime import datetime

# init the colorama module
colorama.init()

GREEN = colorama.Fore.GREEN
GRAY = colorama.Fore.LIGHTBLACK_EX
RESET = colorama.Fore.RESET
YELLOW = colorama.Fore.YELLOW

# initialize the set of links (unique links)
internal_urls = set()
external_urls = set()

total_urls_visited = 0


def is_valid(url):
    """
    Checks whether `url` is a valid URL.
    """
    parsed = urlparse(url)
    return bool(parsed.netloc) and bool(parsed.scheme)


def get_all_website_links(url):
    """
    Returns all URLs that is found on `url` in which it belongs to the same website
    """
    # all URLs of `url`
    urls = set()
    # domain name of the URL without the protocol
    domain_name = urlparse(url).netloc
    # initialize an HTTP session
    session = HTMLSession()
    # make HTTP request & retrieve response
    response = session.get(url)
    # execute Javascript
    try:
        response.html.render()
    except:
        pass
    soup = BeautifulSoup(response.html.html, "html.parser")
    for a_tag in soup.findAll("a"):
        href = a_tag.attrs.get("href")
        if href == "" or href is None:
            # href empty tag
            continue
        # join the URL if it's relative (not absolute link)
        href = urljoin(url, href)
        parsed_href = urlparse(href)
        # remove URL GET parameters, URL fragments, etc.
        href = parsed_href.scheme + "://" + parsed_href.netloc + parsed_href.path
        if not is_valid(href):
            # not a valid URL
            continue
        if href in internal_urls:
            # already in the set
            continue
        if domain_name not in href:
            # external link
            if href not in external_urls:
                print(f"{GRAY}[!] External link: {href}{RESET}")
                external_urls.add(href)
            continue
        print(f"{GREEN}[*] Internal link: {href}{RESET}")
        urls.add(href)
        internal_urls.add(href)
    return urls


def crawl(url, max_urls=30):
    """
    Crawls a web page and extracts all links.
    You'll find all links in `external_urls` and `internal_urls` global set variables.
    params:
        max_urls (int): number of max urls to crawl, default is 30.
    """
    global total_urls_visited
    total_urls_visited += 1
    print(f"{YELLOW}[*] Crawling: {url}{RESET}")
    links = get_all_website_links(url)
    for link in links:
        if total_urls_visited > max_urls:
            break
        crawl(link, max_urls=max_urls)


if __name__ == "__main__":
    while True:
        import argparse
        parser = argparse.ArgumentParser(description="Link Extractor Tool with Python")
        parser.add_argument("url",help="The URL to extract links from.")
        parser.add_argument("-m", "--max-urls", help="Number of max URLs to crawl, default is 30.", default=30, type=int)
        
        args = parser.parse_args()
        url = args.url
        max_urls = args.max_urls

        crawl(url, max_urls=max_urls)

        print("[+] Total Internal links:", len(internal_urls))
        print("[+] Total External links:", len(external_urls))
        print("[+] Total URLs:", len(external_urls) + len(internal_urls))
        print("[+] Total crawled URLs:", max_urls)

        domain_name = urlparse(url).netloc

        # save the internal links to a file
        with open(f"{domain_name}_internal_links.csv", "w") as f:
            for internal_link in internal_urls:
                print(internal_link.strip(), file=f)

        # save the external links to a file
        with open(f"{domain_name}_external_links.csv", "w") as f:
            for external_link in external_urls:
                print(external_link.strip(), file=f)
        
        
        
        df = pd.read_csv(f"{domain_name}_internal_links.csv", encoding='utf-8',header=None)
        
        for index, websites in df.iterrows():
                now = datetime.now()
                current_time = now.strftime("%H:%M:%S")
                print(index, websites[0])
                try:
                        response = requests.get(websites[0])
                        #print(response.status_code)
                        df.at[index, 'status_code'] = "Site is available {}".format(response.status_code)
                        df.at[index, 'time_check'] = current_time
                except:
                        df.at[index, 'status_code'] = "Site is not available"
                        df.at[index, 'time_check'] = current_time
                        #print('Website {} is not available'.format(websites[0]))

        print(df)

        with open(f"{domain_name}_fail_try.csv", "a") as f:
            if not(df[df['status_code'] == "Site is not available"].empty):
                print(df[df['status_code'] == "Site is not available"], file=f)

        
        df = pd.read_csv(f"{domain_name}_external_links.csv", encoding='utf-8',header=None)
        
        for index, websites in df.iterrows():  
                now = datetime.now()
                current_time = now.strftime("%H:%M:%S")
                print(index, websites[0])
                try:
                        response = requests.get(websites[0])
                        #print(response.status_code)
                        df.at[index, 'status_code'] = "Site is available {}".format(response.status_code,)
                        df.at[index, 'time_check'] = current_time
                except:
                        df.at[index, 'status_code'] = "Site is not available"
                        df.at[index, 'time_check'] = current_time
                        #print('Website {} is not available'.format(websites[0]))

        print(df)

        with open(f"{domain_name}_fail_try.csv", "a") as f:
            if not(df[df['status_code'] == "Site is not available"].empty):
                print(df[df['status_code'] == "Site is not available"], file=f)

        time.sleep(10)