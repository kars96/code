import requests
from bs4 import BeautifulSoup as bs
import re

url = 'http://www.smartprix.com/products/?q='
ip = str(input('Enter product name:'))
url += '+'.join(ip.split())
url += '&cat=all'
print(url)

try:
	r = requests.get(url)
except Exception:
	print('error occured')

if(r.status_code is not 200):
	print(r.status_code)
	exit()

s = bs(r.content, 'html.parser')
if re.match(input('Do you want to view source code:[y|Y]'), r'y|Y'):
	print(s.prettify())

html = list(s.children)[2]

print(type(html))

names = []
links = []
ul = html.find('ul', class_='list-content')
for i in ul.children:
	# print(type(i))
	if str(type(i)) == "<class 'bs4.element.Tag'>" :
		# print(in)
		d = i.find_all('div', class_='info')
		for j in d:
			names.append(j.find('h2').get_text())
			links.append(j.select('h2 a')[0]['href'])


for i in range(len(names)):
	print("%2d %30s %s"%(i,names[i],links[i]))