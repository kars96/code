import PyPDF2
from sys import argv

f = open(argv[1], "rb")
ft = open(argv[1].split('.')[0]+".txt", "w")

pr = PyPDF2.PdfFileReader(f)

print("No.pages "+pr.numPages)

s = ""
s += pr.getPage(0).extractText()
s += pr.getPage(1).extractText()
