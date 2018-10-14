#!/bin/python
import numpy as np
n=int(input())
N=list(map(float,input().strip().split(' ')))
w=list(map(float,input().strip().split(' ')))
print(sum(np.multiply(N,w))/sum(w))