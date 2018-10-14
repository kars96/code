# Enter your code here. Read input from STDIN. Print output to STDOUT
n=gets.chomp
n.times {
    s=gets.chomp
    px,py,qx,qy= s.split(' ')
    px-=qx
    py-=qy
    puts()
}