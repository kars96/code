from django.db import models

import uuid
# Create your models here.
class Genre(models.Model):
	name = models.CharField(max_length = 40, help_text='Enter a book genre')

	def __str__(self):
		return self.name


class Author(models.Model):
	name = models.CharField(max_length = 100)
	date_of_birth = models.DateField()
	date_of_death = models.DateField()

	def __str__(self):
		return self.name


class Language(models.Model):
	name = models.CharField(max_length = 20)

	def __str__(self):
		return name


class Book(models.Model):
	title = models.CharField(max_length=200)
	author = models.ForeignKey(Author, on_delete=models.SET_NULL, null=True )
	summary = models.TextField(max_length=1000)
	imprint = models.CharField(max_length=100)
	isbn = models.IntegerField('ISBN', max_length=13, help_text='13 character isbn')
	genre = models.ManyToManyField(Genre, help_text='Select a genre for this book')
	language = models.OneToOneField(Language)

	def get_absolute_url(self):
		return reverse('book-detail', args=[str(self.id)])

class BookInstance(models.Model):
	uniqueId = models.CharField()
	due_back = models.DateField()
	status = 
	book = models.ForeignKey(Book)

