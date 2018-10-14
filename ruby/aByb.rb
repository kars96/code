require_relative 'gcf'
a=10
b=3
if a%b == 0
	c, d = (a/b).to_i, 1
elsif b%a == 0
	c, d = 1, (b/a).to_i
else
	g = gcd(a,b)
	c = (a/g).to_i
	d = (b/g).to_i
end

print(c,"/",d)
