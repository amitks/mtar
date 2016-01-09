/*******************************************************\
 * **
 * ** Filename : replace_token.c
 * **
 * ** Description : replaces a particular word string with a token val.
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

char *replace_token(char * pstrBuf) {
	
	g_pstrTmp_val = malloc(strlen(pstrBuf)*sizeof(char));
	g_pstrData_val = malloc(strlen(pstrBuf)*sizeof(char));
	g_pstrToken_val = malloc(strlen(pstrBuf)*sizeof(char));
	strcpy(g_pstrTmp_val, pstrBuf);
	FILE * fp_token = fopen("token-table.dat", "r");
	if(fp_token == NULL) exit (EXIT_FAILURE );
	while(fscanf(fp_token, "%s %s" , g_pstrData_val, g_pstrToken_val) >= 0) {
		if( strcmp(g_pstrData_val, pstrBuf) == 0 ) {
			strcpy(g_pstrTmp_val, g_pstrToken_val);
			break;
		}
	}	
	fclose(fp_token);
	return g_pstrTmp_val;
}
