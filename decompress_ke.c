/*******************************************************\
 * **
 * ** Filename
 * **
 * ** Description
 * **
 * ** 
 * ** Copyright (cCh) <date> <company>
 * ** All Rights Reserved
 * **
 * ** Author:
 * **    Authors
 * **
 * ** General Comments
 * **
 * **
 * ** $Header: $
 * **
 * **
 * ** $Log: $
 * **
 * \*******************************************************/
#include "mytar.h"

int decompress_ke(char * pstrFile_src, char* pstrFile_dest){
	
	FILE *fp_src = fopen(pstrFile_src, "r");
	if(fp_src == NULL)
		return EXIT_FAILURE;
	FILE *fp_dest = fopen(pstrFile_dest, "w");
	if(fp_src == NULL)
		return EXIT_FAILURE;
	char szBuf[BUFSIZE];	
	char cCh;
	int nCount = 0;
	printf("KEYWORD DECOMPRESS ## FILE = %s\n", pstrFile_src);
	while ( (cCh = fgetc(fp_src) ) != EOF ) {
		if(isspace(cCh)){
			if(nCount) 
			fprintf(fp_dest, "%s", replace_word(szBuf));
			nCount = 0;
		}
		while(isspace(cCh)) {			
			fprintf(fp_dest, "%c", cCh);
			cCh = fgetc(fp_src);
		}
		if(!isspace(cCh)){
			if(cCh != '\n' || cCh != '\t' ) {
				if(cCh != '\\') {
					if(cCh == (char)224) cCh = '\\' ;
					if(cCh == (char)225) cCh = '$' ;
					szBuf[nCount++] = cCh;
					szBuf[nCount] = '\0';	
				}
			}			
			else	
				fprintf(fp_dest, "%c", cCh);
		}
	}
	if(nCount > 1)
			fprintf(fp_dest, "%s", replace_word(szBuf));
	fclose(fp_src);
	fclose(fp_dest);
	return 0;
}
