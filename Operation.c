#include "Operation.h"
#include <stdlib.h>
#include <stdio.h>

Status InitStack (SqStack *S)
{
	S->base=(SElemType*)malloc(MAXSIZE*sizeof(SqStack));
	if(!(S->base)) 
	{
		exit(OVERFLOW);
	}
	else 
	{
		S->top=S->base;
		S->stacksize=MAXSIZE;
		return OK;
	}
}

Status StackEmpty(SqStack S)
{
	if(S.top==S.base)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

int StackLength(SqStack S)
{
	return S.top-S.base;
} 

void ClearStack(SqStack S)
{
	if(S.base) S.top=S.base;
}

void DestoryStack(SqStack *S)
{
	if(S->base)
	{
		free(S->base);
		S->stacksize=0;
		S->base=NULL;
		S->top=S->base;
	}
} 

Status Push(SqStack *S,SElemType e)
{
	if(S->top-S->base==S->stacksize)
	{
		return ERROR;
	}
	else 
	{
		*(S->top)=e;
		S->top++;
		return OK;
	}
}

Status Pop(SqStack *S,SElemType *e)
{
	if(StackEmpty(*S))
	{
		return ERROR;
	}
	else
	{
		S->top--;
		*e=*(S->top);
		return OK;
	}
 } 


Status Compare(SElemType *A,int *CurrentA,int Input,SqStack *Q)
{
	if(A[*CurrentA]>Input)
	{
		Push(Q,Input);
	}
	else if(A[*CurrentA]==Input)
	{
		(*CurrentA)++;
	}
	else
	{
		return ERROR;
	}
	return OK;
}

Status RightOut(SqStack S,SElemType *A)
{
	int i,flag,j;
	int CurrentA,Input;
	SqStack Q;
	i=StackLength(S);
	CurrentA=0;
	InitStack(&Q);
	flag=TRUE;
	for(Input=1;Input<=i;Input++)
	{
		if(StackEmpty(Q))
		{
			flag=Compare(A,&CurrentA,Input,&Q)?1:0;
			if(!flag) break;
		}
		else
		{
			if(A[CurrentA]>*(Q.top-1))
			{
				flag=Compare(A,&CurrentA,Input,&Q)?1:0;
				if(!flag) break;
			}
			else if(A[CurrentA]==*(Q.top-1))
			{
				Pop(&Q,A+CurrentA);
				CurrentA++;
				Input--;
			}
			else
			{
				flag=0;
				break;
			}
		}
	}
	return flag;
}

void Print(SElemType Out[],int i)
{
	int j;
	for(j=0;j<i;j++)
	{
		printf("%d ",Out[j]);
	}
 } 
void legalSequence(SqStack S,SElemType In[],SElemType Out[],int len,int i,int j)
{
	
	SElemType x,k;
	if(StackEmpty(S)&&j>=len)
	{
		Print(Out,len);
		printf("\n");
	}
	else if(!StackEmpty(S)&&i<len)
	{
		Pop(&S,&x);
		Out[j]=x;
		j++;
		legalSequence(S,In,Out,len,i,j);
		j--;
		Push(&S,x);
		Push(&S,In[i]);
		i++;
		legalSequence(S,In,Out,len,i,j);
		i--;
		Pop(&S,&k);
	}
	else if(!StackEmpty(S)&&i>=len)
	{
		Pop(&S,&x);
		Out[j]=x;
		j++;
		legalSequence(S,In,Out,len,i,j);
		j--;
		Push(&S,x);
	}
	else if(StackEmpty(S)&&i<len)
	{
		Push(&S,In[i]);
		i++;
		legalSequence(S,In,Out,len,i,j);
		i--;
		Pop(&S,&k);
	}
}
