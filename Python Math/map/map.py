from bs4 import BeautifulSoup
xml = open('map.osm', 'r', encoding='utf8').read()
soup = BeautifulSoup(xml, 'xml')

cnt = 0
sh = 0
print ('HI')
for node in soup.find_all('node'):
    for tag in node('tag'):
        if (tag['k'] == 'public_transport' and tag['v'] == 'stop_position'):
            cnt += 1
            print('BUS stop : ',cnt)
        if (tag['k'] == 'description' and tag['v'] == 'susi-bar'):
            sh += 1
            print('Sushi bar : ',cnt)