import re
import string
from sys import argv

p = re.compile(r'[^a-zA-Z0-9.]+')


f = open(argv[1], 'r')
s = f.read().splitlines()

s = " ".join(s)

s = p.sub(' ',s)

f.close()
f = open(argv[1], 'w')
f.write(s)
f.close()
# print()