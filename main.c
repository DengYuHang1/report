#include <stdio.h>
#include <stdlib.h>
#include "Operation.h"

int ACM(int M,int N);

int main(int argc, char *argv[])
{

	int n,m;
	printf("%d",ACM(1,0));
	return 0;
}

int ACM(int M,int N)
{
	if(M==0)return N+1;
	else if(N==0)return ACM(M-1,1);
	else return ACM(M-1,ACM(M,N-1));
}
