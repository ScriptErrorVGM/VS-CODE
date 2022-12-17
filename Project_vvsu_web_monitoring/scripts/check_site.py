# -*- encoding: utf-8 -*-

import requests
import urllib.request
import subprocess
import pandas as pd

df = pd.read_csv("C:/Users/Grigory/Documents/VS CODE/VS-CODE/Project_vvsu_web_monitoring/websites.csv", encoding='utf-8',header=None)
#df.columns = df.iloc[0]
#df.drop(index=0, inplace=True)
print(df)
for index, websites in df.iterrows():
        print(index, websites[0])
        try:
                response = requests.get(websites[0])
                #print(response.status_code)
                df.at[index, 'status_code'] = "Site is available {}".format(response.status_code)
        except:
                df.at[index, 'status_code'] = "Site is not available"
                #print('Website {} is not available'.format(websites[0]))

print(df)
#response = requests.get("http://www.google.com")
#print(response.status_code)


'''

try:
        urllib.request.urlopen('http://www.google.com')
except ValueError:
        print("Oops!  That was no valid adress.  Try again...")
else:
        print("Response : ",urllib.request.urlopen('http://www.google.com').getcode())
'''



'''
headers_mobile = { 'User-Agent' : 'Mozilla/5.0 (iPhone; CPU iPhone OS 9_1 like Mac OS X) AppleWebKit/601.1.46 (KHTML, like Gecko) Version/9.0 Mobile/13B137 Safari/601.1'}

request = urllib.request.Request('http://www.stackoverflow.com')
response = urllib.request.urlopen(request).getcode()
request_mobile = urllib.request.Request('http://www.stackoverflow.com', headers=headers_mobile)
response_m = urllib.request.urlopen(request_mobile).getcode()

print(response)
print(response_m)
if response != 200 or response_m != 200:
    subprocess.run(["systemctl", "restart", "nginx"])

'''
