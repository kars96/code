
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
count_vect = CountVectorizer()
# kw = []
# with open('keywords.txt', 'r') as f:
# 	kw = f.read().splitlines()


# count_vect.fit(kw)
# print(count_vect.vocabulary_)

x = count_vect.fit_transform(predictor)




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

import pickle
pickle.dump(clf, open('mlv2model.sav', 'wb'))
pickle.dump(count_vect, open('count_vect.sav', 'wb'))
xt = count_vect.transform(predictort)

import numpy as np
predicted = clf.predict(xt)
print(predicted)
print(np.mean(predicted == targett))