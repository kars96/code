from django.shortcuts import render, get_object_or_404
from django.template import loader
from django.http import HttpResponse, Http404, HttpResponseRedirect
from django.urls import reverse
from django.views import generic

from .models import Question, Choice

# def index(request):
# 	latest_questions = Question.objects.order_by('-pub_date')[:5]
# 	# question_list = latest_questions
# 	context = { 'questions_list': latest_questions,}
# 	# template = loader.get_template('polls/index.html')
# 	# # output = ", ".join([q.question_text for q in latest_questions])
# 	# return HttpResponse(template.render(context, request))

# 	return render(request, 'polls/index.html', context)

# def detail(request, question_id):
# 	# try:
# 	# 	question = Question.objects.get(pk=question_id)
# 	# except Question.DoesNotExist as e:
# 	# 	raise Http404("Question does not exist")
# 	question = get_object_or_404(Question, pk=question_id)
# 	return render(request, 'polls/detail.html', {'q' : question})
# 	# return HttpResponse("You're looking at question %s."%question_id)

# def results(request, question_id):
# 	# return HttpResponse("You're looking at the results of question %s" % question_id)
# 	question = get_object_or_404(Question, pk=question_id)
# 	return render(request, 'polls/results.html', {'question': question})

class IndexView(generic.ListView):
	template_name = 'polls/index.html'
	context_object_name = 'questions_list'

	def get_queryset(self):
		return Question.objects.order_by('-pub_date')[:5]

class DetailView(generic.DetailView):
	model = Question
	context_object_name = 'q'
	template_name = 'polls/detail.html'

class ResultsView(generic.DetailView):
	model = Question
	template_name = 'polls/results.html'

def vote(request, question_id):
	question = get_object_or_404(Question, pk=question_id)
	try:
		selected_choice = question.choice_set.get(pk=request.POST['choice'])
	except (KeyError, Choice.DoesNotExist):
		return render(request, 'polls/detail.html', { 'q': question, 'error_message':'You didnt select a choice'})
	else:
		selected_choice.votes += 1
		selected_choice.save()
		return HttpResponseRedirect(reverse('polls:results', args=(question.id,)))
