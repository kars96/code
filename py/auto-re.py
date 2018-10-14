import re

ph_pattern = re.compile(r'\b(\d{3})-(\d{3})-(\d{4})\b')
ph_pattern2= re.compile(r'\b\d{3}-\d{3}-\d{4}\b')

no = ph_pattern.search('my number is 123-456-7980 345-323-6790')
if no:
	print(f'Phone number found is {no.group(2)}, {no.groups()}') 
	first, sec, third = no.groups()
	print(first, sec, third)

batregex = re.compile(r'Bat(man|girl|bat)')
bats = batregex.search('Bat Batbat')
if bats:
	print(bats.group(0))

haregex = re.compile(r'(ha){3,5}') #greedy default
has = haregex.search('hahahahahaha')
if has:
	print(has.group())



haregex = re.compile(r'(ha){3,5}?') #non-greedy default
has = haregex.search('amamhahahahaama')
if has:
	print(has.group())

no = ph_pattern.findall('my number is 123-456-7980 345-323-6790')
if no:
	print(no)

no = ph_pattern2.findall('my number is 123-456-7980 345-323-6790')
if no:
	print(no)

# \d Any numeric digit from 0 to 9.
# \D Any character that is not a numeric digit from 0 to 9.
# \w Any letter, numeric digit, or the underscore character.
# (Think of this as matching “word” characters.)
# \W Any character that is not a letter, numeric digit, or the
# underscore character.
# \s Any space, tab, or newline character. (Think of this as
# matching “space” characters.)
# \S Any character that is not a space, tab, or newline.

nongreedyregex = re.compile(r'<.*?>')
print(nongreedyregex.search('<To serve man> for dinner>').group())

greedyregex = re.compile(r'<.*>')
print(greedyregex.search('<To serve man> for dinner>ha').group())

phoneRegex = re.compile(r'''(
(\d{3}|\(\d{3}\))?
(\s|-|\.)?
\d{3}
(\s|-|\.)
\d{4}
(\s*(ext|x|ext.)\s*\d{2,5})?
)''', re.VERBOSE)

xregex = re.compile(r'foo', re.IGNORECASE | re.DOTALL )
  