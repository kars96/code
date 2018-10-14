from elasticsearch import Elasticsearch
es = Elasticsearch([{'host': 'localhost', 'port': 9200}])

import json
i=1
with open('data.json') as data:
	d = json.load(data)
	print(d)
	es.index(index='sw', doc_type='people', id=i, body=d)
	i+=1