from django.contrib import admin

# Register your models here.
from .models import Question, Choice

class ChoiceInline(admin.TabularInline):
	model = Choice
	extra = 0

class QuestionAdmin(admin.ModelAdmin):
	# fields = ['pub_date', 'question_text']
	fieldsets = [
		(None, {'fields':['question_text']}),
		('Date information',{'fields':['pub_date']}),
	]
	inlines = [ChoiceInline]
	search_fields = ['question_text']
	list_filter = ['pub_date', ]
	list_display = ('question_text', 'pub_date', 'recently_published', )

admin.site.register(Question, QuestionAdmin)

# admin.site.register(Choice)