/*******************************************************\
 * **
 * ** Filename : stack.c
 * **
 * ** Description : this files contains small modules like push and pop for operation on stack.
 * **		
 * ** 
 * ** Copyright (c) <20/06/2013> GNU
 * ** All Rights Reserved
 * **
 * ** Author:
 * **    Authors: AMIT KUMAR 
 * **		  
 * ** General Comments
 * **
 * **
 * ** $Header: $ mytar.h
 * **
 * **
 * ** $Log: $
 * **
 * \*******************************************************/
#include "mytar.h"
STACK* stack_init( int nSize )
{
	STACK *pStk;
	pStk = (STACK *)malloc(sizeof(STACK*));
	pStk->stack = malloc(sizeof(int) * nSize);
	pStk->nTop = -1;
	pStk->nSize = nSize;
	return pStk;
}
stack_cleanup(STACK * pStk)
{
	free(pStk->stack);
	free(pStk);		
}
push(STACK * pStk, int data)
{
	if(pStk->nTop == pStk->nSize) 
		printf("STACK OVERFLOW!\n");
	*(pStk->stack+(++pStk->nTop)) = data;
}
int pop(STACK * pStk)
{
	if(pStk->nTop == -1)	
		return -1;
	return *(pStk->stack+pStk->nTop--);
}
print_stack(STACK *pStk)
{
	int nCount;
	for(nCount = pStk->nTop ; nCount >= 0; nCount--) printf("%d\n", *(pStk->stack+nCount));
}
