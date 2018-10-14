#!/bin/python
import re
n=int(input())
for i in range(n):	
	patter=r"<a href=\"([^\"]*)\"[^>]*>(.*)</a>"
	match=re.findall(patter,input())
	for i in match:
		print (i[0],end=',')
		match2=re.search(r"(<[^>]*>)*([^<]*)",i[1])
		# print(match2.groups())
		if match2:
			print(match2.group(2))