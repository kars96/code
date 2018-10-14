from nltk import word_tokenize
from nltk.corpus import stopwords
import string
s = []
while True:
	sent = input()
	if sent is None:
		break
	stop = stopwords.words('english') + list(string.punctuation)
	s+=[i for i in word_tokenize(sent.lower()) if i not in stop]
	print(s)