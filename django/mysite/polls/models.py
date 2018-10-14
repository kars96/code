from django.db import models

import datetime
from django.utils import timezone
# Create your models here.


class Question(models.Model):
	"""docstring for Question"""
	question_text = models.CharField(max_length = 200)
	pub_date = models.DateTimeField("date published")
	def __str__(self):
		return self.question_text

	def recently_published(self):
		return timezone.now() >= self.pub_date >= timezone.now() - datetime.timedelta(days = 1)
	recently_published.admin_order_field = 'pub_date'
	recently_published.boolean = True
	recently_published.short_description = 'Published Recently?'

class Choice(models.Model):
	"""docstring for Choice"""
	question = models.ForeignKey(Question, on_delete=models.CASCADE)
	choice_text = models.CharField(max_length = 200)
	votes  = models.IntegerField(default = 0)
	def __str__(self):
		return self.choice_text

