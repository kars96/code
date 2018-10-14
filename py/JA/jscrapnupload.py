import json
from bs4 import BeautifulSoup as bs
import requests
from sys import stdout
import pycurl
from sys import argv
from io import BytesIO
import pickle

# print("<h3>"+p[0]+"</h3>")
filename="mlv2model.sav" 
model = pickle.load(open(filename, 'rb'))
filename="count_vect.sav"
count_vect = pickle.load(open(filename, 'rb'))

buffer = BytesIO()
username='elastic'
password='CfPiUNPhhwmiT8fCb0ttwUHU'
c = pycurl.Curl()
c.setopt(c.WRITEDATA, buffer)
c.setopt(pycurl.HTTPHEADER, ['Content-Type:application/json'])
c.setopt(c.URL, 'https://19d9d3db50f1892cb8f42aef05cad671.ap-southeast-1.aws.found.io:9243/testja/cases' )
c.setopt(pycurl.USERPWD, username + ':' + password)
c.setopt(c.VERBOSE, True)

stdout = open('new_cases/log', 'a')
js = ""
ruc = open('new_cases/ruc.txt', 'r')
rucid = ruc.readline()
# with open('judg.json', 'r') as f:
# 	js = ''.join(f.readlines())

# print(js)
def scrap_case(u, t):
	global c
	global model
	global count_vect
	global buffer
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
		p = [case['headnote']+case['judgement']]
		xt = count_vect.transform(p)
		r = model.predict(xt)
		cat  = ['land', 'murder', 'theft', 'harassment']
		case['type'] = cat[r[0]] 
		
		# print(case)
		f = open("new_cases/"+t+".json", 'w')
		json.dump(case, f)
		try:
			c.setopt(c.POSTFIELDS, json.dumps(case))
			c.perform()
			print("uploaded")
			content = buffer.getvalue()
			print(content.decode('iso-8859-1'))
		except (pycurl.error):
			errno, errstr = pycurl.error
			print ('An error occurred: '+errstr)
		
	except Exception as e:
		print(e.strerror)
		print("unable to scrap %s %s"%(u, t))
		pass


# print(js['data'])
# print(js.keys())
page = 1
while True:
	js = requests.get('http://judgementstoday.com/api/judgements?limit=5&page='+str(page)).text
	js = json.loads(js)
	js = js['data']['data'] #js contains array of link n name
	if not js:
		break
	flag = False
	for i in js:
		if flag is False:
			ruc = open('new_cases/ruc.txt', 'w')
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


