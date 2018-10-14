
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

xt = count_vect.transform(predictort)

# from sklearn.naive_bayes import MultinomialNB
# clf = MultinomialNB().fit(x, target)
from sklearn.neighbors import KNeighborsClassifier
import numpy as np

for K in range(25):
	K_value = K+1
	neigh = KNeighborsClassifier(n_neighbors = K_value, weights='distance', algorithm='auto')
	neigh.fit(x, target)
	predicted = neigh.predict(xt)

	print(K+1, predicted)
	print(np.mean(predicted == targett))
	
	

# print(predicted)