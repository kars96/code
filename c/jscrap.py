from bs4 import BeautifulSoup

import requests


url ="www.judgementstoday.com/judgements"
r  = requests.get("http://" +url)

data = r.text

print(data)
