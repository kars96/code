import pycurl
from sys import argv
from io import BytesIO

buffer = BytesIO()
username='elastic'
password='CfPiUNPhhwmiT8fCb0ttwUHU'
for i in range(2, len(argv)):
	with open(argv[i], 'r') as f:
		s  = f.read()
		c = pycurl.Curl()
		c.setopt(c.WRITEDATA, buffer)
		c.setopt(pycurl.HTTPHEADER, ['Content-Type:application/json'])
		c.setopt(c.URL, 'https://19d9d3db50f1892cb8f42aef05cad671.ap-southeast-1.aws.found.io:9243/ja/cases' )
		c.setopt(pycurl.USERPWD, username + ':' + password)
		c.setopt(c.VERBOSE, True)
		c.setopt(c.POSTFIELDS, '{"type":"%s", "content":"%s"}'%(argv[1], s))
		try:
			c.perform()
		except (pycurl.error, error):
			errno, errstr = error
			print ('An error occurred: '+errstr)
			# return False, ''
		c.close()
		content = buffer.getvalue()
		print(content.decode('iso-8859-1'))