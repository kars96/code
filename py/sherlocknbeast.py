t=int(input().strip())
for a0 in range(t):
	# print("hi")
	n=int(input().strip())
	t1=n
	t2=n-t1
	f=1
	tempt1,tempt2=0,0
	for k in range(n//2+1):
		if t1 % 3 is 0 and t2 % 5 is 0:
			break
		if t1 % 5 is 0 and t2 % 3 is 0:
			tempt1 , tempt2 = t1 , t2
		t1-=1
		t2+=1
	else:
		if tempt1 is not 0 or tempt2 is not 0:
			print(tempt2*'5'+tempt1*'3')
			# break
		else:
			print(-1)
		f=0
	if f is 1:
		print(t1*'5'+t2*'3')

