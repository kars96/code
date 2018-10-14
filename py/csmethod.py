class Employee(object):
	"""docstring for Employee"""
	raise_amt = 1.4
	def __init__(self, eid, name):
		super(Employee, self).__init__()
		self.name = name
		self.id = eid

	@staticmethod
	def is_workday(day):
		if day.weekday() == 5 or day.weekday() == 6:
			return True
		return False

	@classmethod
	def from_string(cls, s):
		eid, name = s.split('-')
		return cls(eid, name)

e = Employee(1, 'karhtik')
e2 = Employee.from_string('2-kars')
from datetime import date
date1 = date(2018, 5,1)
print(Employee.is_workday(date1))

print(e2.name)
print(e2.id)
		