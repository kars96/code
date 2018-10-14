=begin
a= to_i(gets.chomp)
b= to_i(gets.chomp)
=end
def gcd(a,b)
	# a=to_i(a)
	# b=to_i(b)
		# print(a,b)

	while(a != 0)
		# print(a,b,"\n")
		r = b%a
		b=a
		a=r
	end
	return b
end

if __FILE__ == $0
a=35
b=15

puts "gcd of #{a} and #{b} is #{gcd(35,15)}"
end