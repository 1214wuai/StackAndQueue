#include"StackAndQueue.h"
TestStack()
{
	Stack Stack;
	StackInit(&Stack);
	StackPush(&Stack, 1);
	StackPush(&Stack, 2);
	StackPush(&Stack, 3);
	StackPush(&Stack, 4);
	StackPop(&Stack);
	PrintStack(&Stack);
	DataType Top = StackTop(&Stack);
	printf("\nTop:%d\n", Top);
	size_t size = StackSize(&Stack);
	printf("Size:%d\n", size);
	StackPop(&Stack);
	DataType Top2 = StackTop(&Stack);
	int e1 = StackEmpty(&Stack);
	StackDestroy(&Stack);
	int e2 = StackEmpty(&Stack);
	PrintStack(&Stack);
}
TestQueue()
{
	Queue *Q = QueueInit();
	QueuePush(Q, 1);
	QueuePush(Q, 2);
	QueuePush(Q, 3);
	QueuePush(Q, 4);
	QueuePop(Q);
	DataType head = QueueFront(Q);
	printf("%d\n", head);
	DataType tail = QueueBack(Q);
	printf("%d\n", tail);
	while (Q->_head)
	{
		printf("%d  ", Q->_head->_data);
		QueuePop(Q);
	}
	QueuePush(Q, 1);
	QueuePush(Q, 2);
	QueuePush(Q, 3);

	size_t sz = QueueSize(Q);
	printf("\nsize:%d\n", sz);
	int empty = QueueEmpty(Q);
	
	QueueDestroy(Q);
	int empty2 = QueueEmpty(Q);
	
}

TestQueueByTwoStack()
{
	QueueByTwoStack s;
	QueueByTwoStackInit(&s);
	QueueByTwoStackPush(&s);
	DataType Back0 = QueueByTwoStackFBack(&s);
	DataType Top0 = QueueByTwoStackFront(&s);
	size_t sz0 = QueueByTwoStackSize(&s);
	QueueByTwoStackPop(&s);
	DataType Top1 = QueueByTwoStackFront(&s);
	DataType Back1 = QueueByTwoStackFBack(&s);
	size_t sz1 = QueueByTwoStackSize(&s);
	int e1 = QueueByTwoStackEmpty(&s);
	QueueByTwoStackDestroy(&s);
	int e2 = QueueByTwoStackEmpty(&s);

}
TestStackByTwoQueue()
{
	StackByTwoQueue *Q = StackByTwoQueueInit();
	StackByTwoQueuePush(Q, 1);
	StackByTwoQueuePush(Q, 2);
	StackByTwoQueuePush(Q, 3);
	StackByTwoQueuePush(Q, 4);
	StackByTwoQueuePush(Q, 5);
	StackByTwoQueuePop(Q);
	//StackByTwoQueuePop(Q);
	StackByTwoQueuePop(Q);
	DataType Front = StackByTwoQueueFront(Q);
	DataType Back = StackByTwoQueueBack(Q);
	size_t sz = StackByTwoQueueSize(Q);
	int e1 = StackByTwoQueueEmpty(Q);
	StackByTwoQueDestroy(Q);
	int e2 = StackByTwoQueueEmpty(Q);

}
TestDiagnoseStack()
{
	QueueByTwoStack s;
	int Stack_out[] = { 4,5,3,2,1 };
	int Stack_in[] = { 1,2,3,4,5 };
	int len_out = sizeof(Stack_out)/sizeof(Stack_out[0]);
	int len_in = sizeof(Stack_in) / sizeof(Stack_in[0]);
	QueueByTwoStackInit(&s);
	//QueueByTwoStackPush(&s);
	int Y = DiagnoseTack(&s, Stack_out,Stack_in,len_out, len_in);
	if (Y == 0)
	{
		printf("出入栈顺序合法\n");
	}
	else
	{
		printf("出入栈顺序不合法\n");
	}
}
TestOneArrForTwoStack()
{
	int x = 20;
	pOneArrForTwoStack S = OneArrForTwoStackInit(x);
	OneArrForTwoStackPush(S, 1, 1);
	OneArrForTwoStackPush(S, 3, 1);
	OneArrForTwoStackPush(S, 5, 1);
	OneArrForTwoStackPush(S, 7, 1);
	OneArrForTwoStackPush(S, 2, 2);
	OneArrForTwoStackPush(S, 4, 2);
	OneArrForTwoStackPush(S, 6, 2);
	OneArrForTwoStackPush(S, 8, 2);
	int x1 = OneArrForTwoStackTop(S, 1);
	OneArrForTwoStackPop(S, 1);
	int x2 = OneArrForTwoStackTop(S, 1);
	int x3 = OneArrForTwoStackTop(S, 0);
	OneArrForTwoStackPop(S, 0);
	int x4 = OneArrForTwoStackTop(S, 0);
	OneArrForTwoStackPop(S, 0);
	int x5 = OneArrForTwoStackTop(S, 0);
	OneArrForTwoStackPush(S, 9, 1);
	int x6 = OneArrForTwoStackTop(S, 1);
	OneArrForTwoStackDestroy(S);
	int x7 = OneArrForTwoStackTop(S, 1);
}
TestStackMin()
{
	StackMin SM;
	StackMinInit(&SM);
	StackMinPush(&SM,5);
	StackMinPush(&SM, 1);
	StackMinPush(&SM, 1);
	StackMinPush(&SM, 8);
	StackMinPush(&SM, 0);
	DataType min1 = StackMinMin(&SM);
	StackMinPop(&SM);
	DataType min2 = StackMinMin(&SM);
	StackMinPop(&SM);
	DataType min3 = StackMinMin(&SM);
	StackMinPop(&SM);
	DataType min4 = StackMinMin(&SM);
	StackMinPop(&SM);
	DataType min5 = StackMinMin(&SM);
	StackMinDestroy(&SM);
}
int main()
{
	//TestStack();
	//TestQueue();
	//TestQueueByTwoStack();
	TestStackByTwoQueue();
	//TestDiagnoseStack();
	//TestOneArrForTwoStack();
	//TestStackMin();
	system("pause");
}