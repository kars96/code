n=int(input())
s=''
"""fgffhfh"""
while n>0:
	s+=str(n%2)
	n//=2
if s==s[::-1]:
	print(s,"yes")
else:
	print(s[::-1],"no")
