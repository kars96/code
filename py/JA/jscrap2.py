import json
from bs4 import BeautifulSoup as bs
import requests
from sys import stdout

stdout = open('cases/log', 'a')
js = ""
ruc = open('cases/ruc.txt', 'r')
rucid = ruc.readline()
# with open('judg.json', 'r') as f:
# 	js = ''.join(f.readlines())

# print(js)
def scrap_case(u, t):
	try:
		link = "http://judgementstoday.com/api/judgements/%s?search=&page-link=/judgements/%s/%s&token=null"%(u,u,t)
		js = requests.get(link).text
		# print(str(js))
		js = json.loads(str(js))['results']
		# print(js)
		case = {}
		case['url'] = "http://judgementstoday.com/judgements/%s/%s"%(u, t)
		case['title'] = js['title']
		case['date'] = js['published_date']
		case['headnote'] = bs(js['headnote_to_held'], "lxml").get_text()
		case['judgement'] = bs(js['judgement'], "lxml").get_text()
		case['appeal_number'] = js['appeal_number']
		# print(case)
		f = open("cases/"+t+".json", 'w')
		json.dump(case, f)
	except:
		print("unable to scrap %s %s"%(u, t))
		pass


# print(js['data'])
# print(js.keys())
page = 1
while True:
	js = requests.get('http://judgementstoday.com/api/judgements?limit=5&page='+str(page)).text
	js = json.loads(js)
	js = js['data']['data']
	if not js:
		break
	flag = False
	for i in js:
		if flag is False:
			ruc = open('cases/ruc.txt', 'w')
			ruc.write(i['id'])
			flag = True
		if i['id'] is rucid:
			print("update over")
			exit()
		print("scraping  "+i['id'],i['url_title'])
		scrap_case(i['id'], i['url_title'])
		print('done')
	print("**page %d done**"%(page))
	page += 1


