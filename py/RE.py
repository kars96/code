import re
s="Cooldudekarsidude@gmail.com"
pat=r"dude"
print(re.match(pat,s))
if re.search(pat,s):
	print((re.search(pat,s)).group())
print(re.findall(pat,s))
print(re.sub(r"gmail","yahoo",s,1))
