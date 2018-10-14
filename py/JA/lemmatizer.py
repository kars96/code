from nltk.stem import PorterStemmer
from nltk.corpus import stopwords
from nltk.tokenize import word_tokenize
from nltk.stem.wordnet import WordNetLemmatizer
import string
import re
lem = WordNetLemmatizer()
from sys import argv

# obj3=open("sample.txt","r")

# #for i in obj3.readlines():
# 	#print(i.split(" "))
# print(lemmatizer.lemmatize(obj3.read()))

obj3 = open(argv[1], 'r')

s = word_tokenize(obj3.read())

s2 = []
for i in s:
	p = re.compile(r"\d+|['’–@-]")
	if not p.search(i):
		s2.append(re.sub(r'[,.()]', '', i).lower())
s =[ lem.lemmatize(i, pos='n') for i in s2]

if len(argv) == 2:
	print(s)
else:
	op = open(argv[2], 'w')
	op.write('\n'.join(s))
	
