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

Status InitStack (SqStack *S);	//顺序栈初始化
Status StackEmpty(SqStack S);	//判断栈是否为空
int StackLength(SqStack S);		//求栈的长度
void ClearStack(SqStack S);		//清空栈
void DestoryStack(SqStack *S);	//销毁栈 
Status Push(SqStack *S,SElemType e);	//入栈
Status Pop(SqStack *S,SElemType *e);	//出栈 
Status RightOut(SqStack S,SElemType *A);	//判断数组A是否是栈的合法输出序列 
void legalSequence(SqStack S,SElemType In[],SElemType Out[],int len,int i,int j);	//输出所有出栈序列 
#endif
