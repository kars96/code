from nltk.corpus import stopwords
from nltk.tokenize import word_tokenize
import string
from sys import argv
from nltk.stem.wordnet import WordNetLemmatizer
import json
lem = WordNetLemmatizer()
js = {}

obj=open(argv[1],"r")
murf = list(word_tokenize(open('murder.txt', 'r').read()))
thef = list(word_tokenize(open('theft.txt','r').read()))
lanf = list(word_tokenize(open('land.txt', 'r').read()))
harf = list(word_tokenize(open('harassment.txt', 'r').read()))
kw = [{}, {}, {}, {} ]
freq = [0]*4
t = 0
keywords = set()
for i in [murf, thef, lanf, harf]:
	for j in i:
		# j = j.strip('\n\r')
		j = lem.lemmatize(j.lower(), pos='v')
		kw[t][j]=0
		keywords.add(j)
	t += 1
# print(kw)

stop_words = list(stopwords.words('english'))+list(string.punctuation)

word_tokens = list(word_tokenize(obj.read()))



# filtered_sentence = [w for w in word_tokens if not w in stop_words]



filtered_sentence = []

for w in word_tokens:
    if w not in stop_words:
        filtered_sentence.append(w)

t =[ lem.lemmatize(i.lower(), pos='v') for i in filtered_sentence]
# t=filtered_sentence
# print(t)

filtered_sentence = []
for w in t:
	if w in keywords:
		filtered_sentence.append(w)

# print("Extracted keywords-->"+str(filtered_sentence))
js['keywords'] = filtered_sentence
# print('*'*30)
for w in filtered_sentence:
	if w in kw[0]:
		freq[0] += 1
		kw[0][w] += 1
	if w in kw[1]:
		kw[1][w] += 1
		freq[1] += 1
	if w in kw[2]:
		kw[2][w] += 1
		freq[2] += 1
	if w in kw[3]:
		kw[3][w] += 1
		freq[3] += 1

total = sum(freq) if sum(freq) is not 0 else 1
# print ("Frequency of keywords in each category-->"+str(freq))
# print('*'*30)

category = ['murder', 'theft', 'land disputes', 'harassment']
ind = 0
maxx = -1
for i in range(len(freq)):
	if freq[i]>maxx:
		maxx = freq[i]
		ind = i

for i in kw[ind].keys():
	print("%s , %d , %d"%(i,kw[ind][i], ind ))
# for i in range(len(kw)):
# 	print(category[i])
# 	js[category[i]]={}
# 	for j in kw[i].keys():
# 		if kw[i][j] is not 0:
# 			# print('\t%s %d'%(j, kw[i][j]))
# 			js[category[i]][j] = kw[i][j]
# 	js[category[i]]['total']=freq[i]
	# print('*'*10)


# js['result'] = {}
# js['result']['murder'] = freq[0]/total*100
# print('murder %.2f%%'%(freq[0]/total*100))
# js['result']['theft'] = freq[1]/total*100
# print('theft %.2f%%'%(freq[1]/total*100))
# js['result']['land disputes'] = freq[2]/total*100
# print('land %.2f%%'%(freq[2]/total*100))
# js['result']['harassment'] = freq[3]/total*100
# print('harassment %.2f%%'%(freq[3]/total*100))

f = open('output.json', 'w')

json.dump(js, f)

# f2 = open(argv[2], 'w')


# f2.write(" ".join(filtered_sentence))
