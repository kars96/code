
predictor = [] #contains cases statements
target = [] #contains category of the above cases
k = 0
for j in ['land', 'murder', 'theft', 'harassment']:
	for i in range(1,21):
		with open(j+'/case'+str(i)+".txt", 'r') as f:
			predictor.append(f.read().replace('\n', ' '))
			target.append(k)
	k += 1


from sklearn.feature_extraction.text import CountVectorizer
count_vect = CountVectorizer(stop_words='english')

x = count_vect.fit_transform(predictor)

from sklearn.feature_extraction.text import TfidfTransformer
tfidf_transformer = TfidfTransformer()
x = tfidf_transformer.fit_transform(x)



predictort = [] #contains cases statements
targett = [] #contains category of the above cases
k = 0
for j in ['landt', 'murdert', 'theftt', 'harassmentt']:
	for i in range(1,3):
		with open(j+'/case'+str(i)+".txt", 'r') as f:
			predictort.append(f.read().replace('\n', ' '))
			targett.append(k)
	k += 1


from sklearn.naive_bayes import MultinomialNB
clf = MultinomialNB().fit(x, target)

xt = count_vect.transform(predictort)
xt = tfidf_transformer.fit_transform(xt)

import numpy as np
predicted = clf.predict(xt)
print(predicted)
print(np.mean(predicted == targett))