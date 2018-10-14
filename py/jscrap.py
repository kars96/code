from bs4 import BeautifulSoup as bs

# import requests


url ="http://judgementstoday.com/judgements"
# r  = requests.get("http://" +url)

# data = r.content

# print(data)


from selenium import webdriver

driver = webdriver.Firefox()

driver.get(url)

html = driver.page_source

dom = bs(html)

d={}
i = 0
for tag in dom.find_all('a'):
	d[i] = [ tag.text, tag.get('href')]
	print(d[i])
	i += 1