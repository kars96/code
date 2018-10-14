from nltk.corpus import stopwords
from nltk.tokenize import word_tokenize
import string
from sys import argv
from nltk.stem.wordnet import WordNetLemmatizer
lem = WordNetLemmatizer()
from json import loads

obj=open(argv[1],"r")
obj = loads(obj.read())
obj = "HEADNOTE "+obj['headnote']+" JUDGEMENT "+obj['judgement']
murf = open('murder.txt', 'r').readlines()
thef = open('theft.txt','r').readlines()
lanf = open('land.txt', 'r').readlines()
harf = open('harassment.txt', 'r').readlines()
kw = [[], [], [], [] ]
freq = [0]*4
t = 0
keywords = set()
for i in [murf, thef, lanf, harf]:
	for j in i:
		j = j.strip('\n\r')
		kw[t].append(j)
		keywords.add(j)
	t += 1
# print(kw)

stop_words = list(stopwords.words('english'))+list(string.punctuation)
f = open('tempcases/'+argv[1], 'w')
f.write(obj)
word_tokens = list(word_tokenize(obj))



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
# print('*'*30)
for w in filtered_sentence:
	if w in kw[0]:
		freq[0] += 1
	if w in kw[1]:
		freq[1] += 1
	if w in kw[2]:
		freq[2] += 1
	if w in kw[3]:
		freq[3] += 1

total = sum(freq) if sum(freq) is not 0 else 1
# print ("Frequency of keywords in each category-->"+str(freq))
# print('*'*30)

# print('murder %.2f%%'%(freq[0]/total*100))
# print('theft %.2f%%'%(freq[1]/total*100))
# print('land %.2f%%'%(freq[2]/total*100))
# print('harassment %.2f%%'%(freq[3]/total*100))

c = ['murder', 'theft', 'land', 'harassment']
# f2 = open(argv[2], 'w')

print(argv[1],c[freq.index(max(freq))])
# f2.write(" ".join(filtered_sentence))
