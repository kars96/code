def h(q):
	def g(f):
		def d(*args,**kwargs):
			print(q*8)
			f(*args,**kwargs)
			print(q*8)
		return d
	return h

@h("&")
def msg(p):
	print( p)

if __name__=="__main__":
	# msg=g(msg)
	(msg("hiiiiiiiiiii"))