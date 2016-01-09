/*******************************************************\
 * **
 * ** Filename : compress_ke.c
 * **
 * ** Description : Replace more occuring word for token value.
 * **
 * ** 
 * ** Copyright (cCh) <20/06/2013> GNU
 * ** All Rights Reserved
 * **
 * ** Author:
 * **    Authors : AMIT KUMAR 
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

int compress_ke( char *pstrFile_src, char *pstrFile_dest){

	FILE *fp_src = fopen(pstrFile_src, "r");
	FILE *fp_dest = fopen(pstrFile_dest, "w");
	char szBuf[BUFSIZE];	
	char cCh;
	int nCount = 0;
	printf("KEYWORD COMPRESS ## FILE = %s\n", pstrFile_src);
	while ( (cCh = fgetc(fp_src) ) != EOF ) {
		if(isspace(cCh)){
			if(nCount) 
			fprintf(fp_dest, "%s", replace_token(szBuf));
			nCount = 0;
		}
		while(isspace(cCh)) {			
			fprintf(fp_dest, "%c", cCh);
			cCh = fgetc(fp_src);
		}
		if(!isspace(cCh)){
			if(cCh != '\n' || cCh != '\t' ) {
				if(cCh == '\\') cCh = (char)224;
				if(cCh == '$') cCh = (char)225;
				if(isdigit(cCh)) {
					szBuf[nCount] = '\\';
					szBuf[nCount+1] = cCh;
					nCount = nCount + 2;
					szBuf[nCount] = '\0';	
				}else {
					szBuf[nCount++] = cCh;
					szBuf[nCount] = '\0';	
				}
			}			
			else	
				fprintf(fp_dest, "%c", cCh);
		}
	}
	if(nCount > 1)
			fprintf(fp_dest, "%s", replace_token(szBuf));
	fclose(fp_src);
	fclose(fp_dest);
	return 0;
}
