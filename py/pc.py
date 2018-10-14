# def fac(n):
# 	n=int(n)
# 	if n is 0:
# 		return 1
# 	else:
# 		return n*fac(n-1)

# def p(n,r):
# 	return fac(n)/fac(n-r)

f=[1]
def fac(n):
    if (n+1)<len(f):
        return f[n]
    else:
        for i in range(len(f),n+1):
            f.append(f[i-1]*i)
        return f[n]

def p(n,r):
    return fac(n)/fac(n-r)

def c(n,r):
	return p(n,r)/fac(r)


if __name__=='__main__':
	print(eval(input("Enter the Exp\n")))