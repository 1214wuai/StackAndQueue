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
	int _top; //ջ�� 
	int _capacity;//����
}Stack,*pStack;

////////////////////////////////////////////////////// ջ��ʵ�ֽӿ� 
void StackInit(Stack* s);//��ʼ��
void StackPush(Stack* s, DataType x);//��ջ
void PrintStack(Stack *s);//��ӡջ
void StackPop(Stack* s);//��ջ

DataType StackTop(Stack* s);//����ջ��
size_t StackSize(Stack* s);//��ջ�ĳ���
int StackEmpty(Stack* s);//�п�
void StackDestroy(Stack *s);//���
//typedef int DataType;
//////////////////////////////////���нӿڵ�ʵ��
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
////////////////ʵ��һ��ջ��Ҫ��ʵ��Push(��ջ)��Pop(��ջ)��Min(������Сֵ)��ʱ�� ���Ӷ�ΪO(1)
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

//////////////////////////////////////////ʹ������ջʵ��һ������
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
//////////////////////////////////////ʹ����������ʵ��һ��ջ
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
///////////////////////////////Ԫ�س�ջ����ջ˳��ĺϷ��ԡ�����ջ������(1, 2, 3, 4, 5)����ջ����Ϊ
//(4, 5, 3, 2, 1)
int DiagnoseTack(QueueByTwoStack *s, int *Out, int *In,int len_out, int len_in);
//////////////////////////////////////////////һ������ʵ������ջ(����ջ) 
typedef struct OneArrForTwoStack
{
	DataType *p;//����
	int Top1, Top2;//����ջ��
	int MaxSize;//�������Ԫ��
}*pOneArrForTwoStack, OneArrForTwoStack;
pOneArrForTwoStack OneArrForTwoStackInit(int MaxSize);
void OneArrForTwoStackPush(pOneArrForTwoStack S, DataType x, int T);
void OneArrForTwoStackPop(pOneArrForTwoStack S, int T);
int OneArrForTwoStackTop(pOneArrForTwoStack S, int T);
void OneArrForTwoStackDestroy(pOneArrForTwoStack S);
#endif // __STACKANDQUEUE_H__
