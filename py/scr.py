from bs4 import BeautifulSoup as bs
import urllib3 as ur

url ="www.judgementstoday.com/judgements"
http = ur.PoolManager()
r=http.request("GET","http://" +url)
u=ur.urlopen(r)
d=u.read()
print(d)
f=open("wiki.txt","w")
print(f.write(str(d)))
f.close()
