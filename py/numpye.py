import numpy as np 

a = np.array([1,2,3])
print(type(a))
print(a.shape)
print(a[0], a[1], a[2])
a[0] = 5
print(a)

b = np.array([[1,2,3],[4,5,6]])
print(b.shape)
print(b[1,1],b[1][0])

z = np.zeros((3,3))
print(z)

o = np.ones((2,2))
print(o)

f = np.full((2,1,3), 5)
print(f)

i = np.eye(3)
print(i)

r = np.random.random((2,2))
print(r)


a=[[2,3],[4,5]]
b=[[3,2],[5,4]]
print(np.multiply(a, b))
