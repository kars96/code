from nltk.stem import PorterStemmer
from nltk.corpus import stopwords
from nltk.tokenize import word_tokenize
import string
ps = PorterStemmer()

obj=open("testcase.txt","r")

stop_words = list(stopwords.words('english'))+list(string.punctuation)

word_tokens = word_tokenize(obj.read())

filtered_sentence = [w for w in word_tokens if not w in stop_words]

filtered_sentence = []

for w in word_tokens:
    if w not in stop_words:
        filtered_sentence.append(w)
obj1=open("o2.txt","r")

word_tokens1 = word_tokenize(obj1.read())


for w in word_tokens1:
    print(ps.stem(w))

