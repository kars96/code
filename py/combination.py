from copy import copy as cp
def combinations(target,data):
	for i in range(len(data)):
		new_target=cp(target)
		# new_data=c(data)
		new_target.append(data[i])
		new_data=cp(data[i+1:])
		print(new_target)
		combinations(new_target, new_data)

if __name__ == "__main__":
# print(__name__)
	combinations([],[1,2,3])