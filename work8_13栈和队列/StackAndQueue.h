#ifndef __STACKANDQUEUE_H__
#define __STACKANDQUEUE_H__
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
typedef int DataType;
#define N 10
typedef struct BinaryTreeNode BDataType;
typedef struct Stack
{
	DataType* _array;
	int _top; //栈顶 
	int _capacity;//容量
}Stack,*pStack;

////////////////////////////////////////////////////// 栈的实现接口 
void StackInit(Stack* s);//初始化
void StackPush(Stack* s, DataType x);//入栈
void PrintStack(Stack *s);//打印栈
void StackPop(Stack* s);//弹栈

DataType StackTop(Stack* s);//返回栈顶
size_t StackSize(Stack* s);//求栈的长度
int StackEmpty(Stack* s);//判空
void StackDestroy(Stack *s);//清空
//typedef int DataType;
//////////////////////////////////队列接口的实现
typedef struct QueueNode
{
	DataType _data;
	struct QueueNode* _next;
	
}QueueNode;

typedef struct Queue
{
	QueueNode* _head;
	QueueNode* _tail;
	
}Queue;

Queue* QueueInit();
void QueuePush(Queue* q, DataType x);
void QueuePop(Queue* q);
DataType QueueFront(Queue* q);
DataType QueueBack(Queue* q);
size_t QueueSize(Queue* q);
int QueueDestroy(Queue* q);
int QueueEmpty(Queue* q);
////////////////实现一个栈，要求实现Push(出栈)、Pop(入栈)、Min(返回最小值)的时间 复杂度为O(1)
typedef struct StackMin
{
	Stack st;
	Stack Min;
}StackMin;
void StackMinInit(StackMin* s);
void StackMinPush(StackMin*s, DataType x);
void StackMinPop(StackMin* s);
DataType StackMinMin(StackMin *s);
void StackMinDestroy(StackMin* s);

//////////////////////////////////////////使用两个栈实现一个队列
typedef struct QueueByTwoStack
{
	Stack s1;
	Stack s2;
}QueueByTwoStack;

void QueueByTwoStackInit(QueueByTwoStack *s);
void QueueByTwoStackPush(QueueByTwoStack *s);
void QueueByTwoStackPop(QueueByTwoStack *s);
DataType QueueByTwoStackFront(QueueByTwoStack *s);
DataType QueueByTwoStackFBack(QueueByTwoStack *s);
size_t QueueByTwoStackSize(QueueByTwoStack *s);
int QueueByTwoStackEmpty(QueueByTwoStack *s);
void QueueByTwoStackDestroy(QueueByTwoStack *s);
//////////////////////////////////////使用两个队列实现一个栈
typedef struct StackByTwoQueue
{
	Queue q1;
	Queue q2;
}StackByTwoQueue;

StackByTwoQueue* StackByTwoQueueInit();
void StackByTwoQueuePush(StackByTwoQueue *Q,DataType x);
void StackByTwoQueuePop(StackByTwoQueue *Q);
DataType StackByTwoQueueFront(StackByTwoQueue *Q);
DataType StackByTwoQueueBack(StackByTwoQueue *Q);
size_t StackByTwoQueueSize(StackByTwoQueue *Q);
int StackByTwoQueueEmpty(StackByTwoQueue *Q);
void StackByTwoQueDestroy(StackByTwoQueue *Q);
///////////////////////////////元素出栈、入栈顺序的合法性。如入栈的序列(1, 2, 3, 4, 5)，出栈序列为
//(4, 5, 3, 2, 1)
int DiagnoseTack(QueueByTwoStack *s, int *Out, int *In,int len_out, int len_in);
//////////////////////////////////////////////一个数组实现两个栈(共享栈) 
typedef struct OneArrForTwoStack
{
	DataType *p;//数组
	int Top1, Top2;//两个栈的
	int MaxSize;//数组最大元素
}*pOneArrForTwoStack, OneArrForTwoStack;
pOneArrForTwoStack OneArrForTwoStackInit(int MaxSize);
void OneArrForTwoStackPush(pOneArrForTwoStack S, DataType x, int T);
void OneArrForTwoStackPop(pOneArrForTwoStack S, int T);
int OneArrForTwoStackTop(pOneArrForTwoStack S, int T);
void OneArrForTwoStackDestroy(pOneArrForTwoStack S);
#endif // __STACKANDQUEUE_H__
