#ifndef	__OPERATION_H
#define __OPERATION_H

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define MAXSIZE 100

typedef int Status;
typedef int SElemType;
typedef	struct{
	SElemType *base;
	SElemType *top;
	int stacksize;
}SqStack;

Status InitStack (SqStack *S);	//˳��ջ��ʼ��
Status StackEmpty(SqStack S);	//�ж�ջ�Ƿ�Ϊ��
int StackLength(SqStack S);		//��ջ�ĳ���
void ClearStack(SqStack S);		//���ջ
void DestoryStack(SqStack *S);	//����ջ 
Status Push(SqStack *S,SElemType e);	//��ջ
Status Pop(SqStack *S,SElemType *e);	//��ջ 
Status RightOut(SqStack S,SElemType *A);	//�ж�����A�Ƿ���ջ�ĺϷ�������� 
void legalSequence(SqStack S,SElemType In[],SElemType Out[],int len,int i,int j);	//������г�ջ���� 
#endif
