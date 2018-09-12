#include"StackAndQueue.h"
void StackInit(Stack* s)
{
	assert(s);
	s->_array = (DataType*)malloc(sizeof(DataType)*N);
	s->_top = 0;
	s->_capacity = N;//10
	return;
}
void StackPush(Stack* s, DataType x)
{
	assert(s);

	if (s->_top == s->_capacity)
	{
		s->_array = (DataType*)realloc(s->_array, (s->_capacity + N) * sizeof(DataType));
	}
	
	s->_array[s->_top] = x;
	s->_top++;
	return;
}

void PrintStack(Stack *s)
{
	assert(s);

	int i = s->_top-1;
	for (i; i >= 0; i--)
	{
		printf("%d  ", s->_array[i]);
	}
}

void StackPop(Stack* s)
{
	assert(s);

	if (s->_top == -1)
	{
		return ;
	}
	//int pop = s->_top-1;
	
	s->_top = s->_top-1;
}

DataType StackTop(Stack* s)
{
	return s->_array[s->_top-1];
}

size_t StackSize(Stack* s)//求栈的长度
{
	assert(s);

	return s->_top;
}
int StackEmpty(Stack* s)//判空
{
	assert(s);

	if (s->_top == 0)
		return 0;
	else
		return 1;
}
void StackDestroy(Stack* s)//清空栈
{
	assert(s);

	free(s->_array);
	s->_array = NULL;
	s->_top = 0;
}

Queue* QueueInit()
{
	

	Queue *q = (Queue*)malloc(sizeof(Queue));
	if (q != NULL)
	{
		q->_head = NULL;
		q->_tail = NULL;
		
	}
	return q;
}

void QueuePush(Queue* q, DataType x)
{
	assert(q);

	QueueNode* Node = (QueueNode*)malloc(sizeof(QueueNode));
	if (Node != NULL)
	{
		Node->_data = x;
		Node->_next = NULL;
	}
	if (q->_head == NULL)
		q->_head = Node;
	else
		q->_tail->_next = Node;
	q->_tail = Node;
}
void QueuePop(Queue* q)
{
	assert(q);

	QueueNode *p = q->_head;
	if (q->_head != NULL)
	{
		q->_head = q->_head->_next;
		
		free(p);
		p = NULL;
	}
	if (q->_head == NULL)
		q->_tail = NULL;
}

DataType QueueFront(Queue* q)
{
	assert(q);
	return q->_head->_data;
}

DataType QueueBack(Queue* q)
{
	assert(q);
	return q->_tail->_data;
}

size_t QueueSize(Queue* q)
{
	assert(q);
	int sz = 0;
	QueueNode *p = q->_head;
	while (p)
	{
		sz++;
		p=p->_next;
	}
	return sz;
}
int QueueEmpty(Queue* q)
{
	assert(q);
	if (q->_head == NULL)
		return 0;
	else
		return 1;
}
int QueueDestroy(Queue* q)
{
	assert(q);
	while (q->_head)
	{
		QueuePop(q);
	}
	if (q->_head == NULL)
		return 1;
	else
		return 0;
}
/////////////////////////////////////////////////////////////
void QueueByTwoStackInit(QueueByTwoStack *s)
{
	assert(s);
	StackInit(&(s->s1));
	StackInit(&(s->s2));
}
void QueueByTwoStackPush(QueueByTwoStack *s)
{
	for (int i = 1; i < 6; i++)
	{
		StackPush(&(s->s1), i);
	}
}
void QueueByTwoStackPop(QueueByTwoStack *s)
{
	assert(s);
	Stack *p1 = &(s->s1);
	Stack *p2 = &(s->s2);
	if(p2->_top >= 0)
	//if(p2->_top > 0)

	{
		StackPop(p2);
	}
	else
	{
		while (p1->_top >= 0)

//		while (p1->_top > 0)
		{
			StackPush(p2, StackTop(p1));
			StackPop(p1);
		}
		StackPop(p2);
	}
}
DataType QueueByTwoStackFront(QueueByTwoStack *s)
{
	assert(s);
	Stack *p1 = &(s->s1);
	Stack *p2 = &(s->s2);
	if (p2->_top > 0)
	{
		return p2->_array[p2->_top-1];
	}
	else
	{
		while (p1->_top != 0)
		{
			StackPush(p2, StackTop(p1));
			StackPop(p1);
		}
		return p2->_array[p2->_top - 1];
	}
}
DataType QueueByTwoStackFBack(QueueByTwoStack *s)
{
	assert(s);

	Stack *p1 = &(s->s1);
	Stack *p2 = &(s->s2);
	if (p1->_top > 0)
		return p1->_array[p1->_top-1];
	else
		return p2->_array[0];

}
size_t QueueByTwoStackSize(QueueByTwoStack *s)
{
	assert(s);

	Stack *p1 = &(s->s1);
	Stack *p2 = &(s->s2);
	if (p1->_top > 0)
		return p1->_top;
	else
		return p2->_top;
}
int QueueByTwoStackEmpty(QueueByTwoStack *s)
{
	assert(s);

	Stack *p1 = &(s->s1);
	Stack *p2 = &(s->s2);
	if ((p1->_top == 0) && (p2->_top == 0))
		return 0;
	else
		return 1;

}
void QueueByTwoStackDestroy(QueueByTwoStack *s)
{
	assert(s);

	Stack *p1 = &(s->s1);
	Stack *p2 = &(s->s2);
	StackDestroy(p1);
	StackDestroy(p2);
	
}
////////////////////////////////////////////////////////////////
StackByTwoQueue* StackByTwoQueueInit()
{
	StackByTwoQueue *Q = (StackByTwoQueue*)malloc(sizeof(StackByTwoQueue));
	Queue *p1 = &(Q->q1);
	Queue *p2 = &(Q->q2);
	
	p1->_head = NULL;
	p1->_tail = NULL;
	p2->_head = NULL;
	p2->_tail = NULL;
	return Q;
}
void StackByTwoQueuePush(StackByTwoQueue *Q,DataType x)
{
	assert(Q);

	Queue *p1 = &(Q->q1);
	Queue *p2 = &(Q->q2);
	if (p1->_head == NULL)
	{
		Queue *tmp = p1;
		p1 = p2;
		p2 = tmp;
	}
	QueuePush(p1, x);
}
void StackByTwoQueuePop(StackByTwoQueue *Q)
{
	assert(Q);

	Queue *p1 = &(Q->q1);
	Queue *p2 = &(Q->q2);
	if (p1->_head == NULL)
	{
		Queue *tmp = p1;
		p1 = p2;
		p2 = tmp;
	}
	while (p1->_head != p1->_tail)
	{
		QueuePush(p2, QueueFront(p1));
		QueuePop(p1);
	}
	QueuePop(p1);
}
DataType StackByTwoQueueFront(StackByTwoQueue *Q)
{
	assert(Q);

	Queue *p1 = &(Q->q1);
	Queue *p2 = &(Q->q2);
	if (p1->_head == NULL)
	{
		Queue *tmp = p1;
		p1 = p2;
		p2 = tmp;
	}
	return p1->_tail->_data;
}
DataType StackByTwoQueueBack(StackByTwoQueue *Q)
{
	assert(Q);
	Queue *p1 = &(Q->q1);
	Queue *p2 = &(Q->q2);
	if (p1->_head == NULL)
	{
		Queue *tmp = p1;
		p1 = p2;
		p2 = tmp;
	}
	return p1->_head->_data;
}
size_t StackByTwoQueueSize(StackByTwoQueue *Q)
{
	assert(Q);

	Queue *p1 = &(Q->q1);
	Queue *p2 = &(Q->q2);
	int sz = 0;
	if (p1->_head == NULL)
	{
		Queue *tmp = p1;
		p1 = p2;
		p2 = tmp;
	}
	QueueNode *p = p1->_head;
	while (p!=NULL)
	{
		sz++;
		p = p->_next;
	}
	return sz;
}

int StackByTwoQueueEmpty(StackByTwoQueue *Q)
{
	assert(Q);
	Queue *p1 = &(Q->q1);
	Queue *p2 = &(Q->q2);
	
	if (p1->_head == NULL)
	{
		Queue *tmp = p1;
		p1 = p2;
		p2 = tmp;
	}
	if (p1->_head == NULL)
		return 0;
	else
		return 1;
}
void StackByTwoQueDestroy(StackByTwoQueue *Q)
{
	assert(Q);
	Queue *p1 = &(Q->q1);
	Queue *p2 = &(Q->q2);
	if (p1->_head == NULL)
	{
		Queue *tmp = p1;
		p1 = p2;
		p2 = tmp;
	}
	/*QueueNode *p = p1->_head;
	while (p->_next != NULL)
	{
		QueueNode *DEL = p;
		p = p->_next;
		free(DEL);
		DEL = NULL;
	}*/
	free(p1->_head);
	p1->_head = NULL;
	free(p1->_tail);
	p1->_tail = NULL;
}
///////////////////////////////////////////////////////////////////////////////////////
int DiagnoseTack(QueueByTwoStack *s, int *Out, int *In, int len_out, int len_in)
{
	assert(s);
	assert(Out);
	assert(In);
	Stack *p1 = &(s->s1);
	Stack *p2 = &(s->s2);
	if (len_out != len_in)//长度不等，不合法
	{
		return 0;
	}
	int i = 0;
	int j = 0;
	for (i = 0; i < len_in; i++)
	{
		StackPush(p1, In[i]);
		while ((StackTop(p1) == Out[j])&&(StackSize > 0))
		{
			StackPop(p1);
			j++;
		} 
	}
	return StackSize(p1);
}
////////////////////////////////////////////////////////////////////////////////
pOneArrForTwoStack OneArrForTwoStackInit(int MaxSize)
{
	pOneArrForTwoStack S = (pOneArrForTwoStack)malloc(sizeof(OneArrForTwoStack));
	S->p = (DataType*)malloc(sizeof(DataType)*MaxSize);
	S->Top1 = 0;
	S->Top2 =1;
	S->MaxSize = MaxSize;
	return S;
}

void OneArrForTwoStackPush(pOneArrForTwoStack S, DataType x, int T)
{
	assert(S);
	DataType* p1 = S->p;
	if (T == 1)
	{
		if (S->Top1 < S->MaxSize)
		{

			p1[(S->Top1)] = x;
			S->Top1 += 2;
		}
		else
			return;
	}
	else
	{
		if (S->Top2 < S->MaxSize)
		{
			p1[(S->Top2)] = x;
			S->Top2 += 2;
		}
		else
			return;
	}
}

void OneArrForTwoStackPop(pOneArrForTwoStack S, int T)
{
	assert(S);
	DataType* p1 = S->p;

	if (T == 1)
	{
		if (S->Top1 == 0)
			return ;
		S->Top1 = S->Top1 - 2;
	}
	else
	{
		if (S->Top1 == 0)
			return ;
		S->Top2 = S->Top2 - 2;

	}
}

int OneArrForTwoStackTop(pOneArrForTwoStack S, int T)
{
	assert(S);
	DataType* p1 = S->p;

	if (T == 1)
	{
		if (S->Top1 == 0)
			return 0;
		return p1[S->Top1-2];
	}
	else
	{
		if (S->Top2 == 1)
			return 0;
		return p1[S->Top2-2];
	}
}
void OneArrForTwoStackDestroy(pOneArrForTwoStack S)
{
	assert(S);
	DataType* p1 = S->p;

	free(p1);
	p1= NULL;
	S->Top1 = 0;
	S->Top2 = 1;
}
/////////////////////////////////////////////////////////////
void StackMinInit(StackMin* s)
{
	assert(s);
	StackInit(&s->st);
	StackInit(&s->Min);
}


void StackMinPush(StackMin* s, DataType x)
{
	assert(s);
	StackPush(&s->st, x);
	if (s->Min._top == 0
		||(x <= StackTop(&s->Min)))
	{
		StackPush(&s->Min, x);
	}
}
void StackMinPop(StackMin* s)
{
	assert(s);
	if (StackTop(&s->Min) == StackTop(&s->st))
	{
		StackPop(&s->Min);
	}
	StackPop(&s->st);
}
DataType StackMinMin(StackMin *s)
{
	assert(s);
	return StackTop(&s->Min);
}

void StackMinDestroy(StackMin* s)
{
	assert(s);
	free(s->Min._array);
	s->Min._array = NULL;
	s->Min._top = 0; 
	free(s->st._array);
	s->st._array = NULL;
	s->st._top = 0;
}