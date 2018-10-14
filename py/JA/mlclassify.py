
import pickle
from sys import argv
# print("Content-type:text/html\r\n\r\n")
# form = cgi.FieldStorage()
# p= [form.getvalue('t')]
print('#',argv,'#')
p = [open(argv[1], 'r').read()]
# p=['a man killed a boy with gun']
# print("<h3>"+p[0]+"</h3>")
filename="mlv2model.sav" 
model = pickle.load(open(filename, 'rb'))
filename="count_vect.sav"
count_vect = pickle.load(open(filename, 'rb'))
xt = count_vect.transform(p)
r = model.predict(xt)
c  = ['land', 'murder', 'theft', 'harassment']
# print("<pre>")
print("category: "+c[r[0]])
# print("</pre>")