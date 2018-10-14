class graph():
	def __init__(self,n):
		self.g={}
		
		for i in range(n):
			self.g[i]=set()
		print(self.g)
		

	def addEdge(self,a,b):
		self.g[a].add(b)
		self.g[b].add(a)

	def dfs(self,start):
		stack=list()
		visited=set()
		stack.append(start)
		visited.add(start)
		print(start)
		while len(stack) is not 0:
			n=stack[-1]
			c=None
			for i in self.g[n]:
				if not( i in visited  ):
					c=i
					break
			if c is None:
				stack.pop()
			else:
				stack.append(c)
				visited.add(c)
				print(c)
		print(visited)
		visited=set()

	def __repr__(self):
		print(self.g)

	def getUnvisitedNode(self, n, visited):
		c=None
		for i in self.g[n]:
			if not( i in visited  ):
				c=i
				break
		return c

	def bfs(self,start):
		queue=list()
		visited=set()
		queue.insert(0,start)
		visited.add(start)
		print(start)
		while len(queue) is not 0:
			n=queue.pop()
			c=self.getUnvisitedNode(n,visited)
			while(c):
				visited.add(c)
				queue.insert(0,c)
				print(c)
				c=self.getUnvisitedNode(n,visited)


if __name__ == '__main__':
	g=graph(6)
	g.addEdge(0,1)
	g.addEdge(0,2)
	g.addEdge(0,3)
	g.addEdge(1,4)
	g.addEdge(1,5)
	g.addEdge(2,5)
	print(g.g)
	g.bfs(0)





