/*******************************************************\
 * **
 * ** Filename : compress_file.c
 * **
 * ** Description : It compress multiple file.
 * **
 * ** 
 * ** Copyright (c) <20/06/2013> GNU
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

int compress_file(char *pstrSrc_file_path, char *pstrDest_file_path, char *pstrFile_name, int nCompress_type) {
	
	char pstrFile_dest[PATH_LENGTH] ;
	char szDest[PATH_LENGTH];
	char szFile_src[PATH_LENGTH];
	char szSrc[PATH_LENGTH];
	
	strcpy(szFile_src, pstrSrc_file_path);
	strcat(szFile_src, "/");
	strcat(szFile_src, pstrFile_name);
	
	strcpy(pstrFile_dest, pstrDest_file_path);
	strcat(pstrFile_dest, "/");
	strcat(pstrFile_dest, pstrFile_name);
	int nCount = 0;
	while(szFile_src[nCount] != '\n') szSrc[nCount] = szFile_src[nCount++] ;
	szSrc[nCount] = '\0';
	nCount = 0;
	while(pstrFile_dest[nCount] != '\n') szDest[nCount] = pstrFile_dest[nCount++] ;
	szDest[nCount] = '\0';
	if(nCompress_type == 1) {
		strcat(szDest, ".nc");
		compress_nc(szSrc, szDest);
	}
	if(nCompress_type == 2){
		strcat(szDest, ".rl");
		compress_rl(szSrc, szDest);
	}
	if(nCompress_type == 3){
		strcat(szDest, ".ke");
		compress_ke(szSrc, szDest);
	}
	if(nCompress_type == 4){
		strcat(szDest, ".nc");
		compress_nc(szSrc, szDest);
		strcpy(szSrc, szDest);
		strcat(szDest, ".rl");
		compress_rl(szSrc, szDest);
		remove(szSrc);
	}
	if(nCompress_type == 5){
		strcat(szDest, ".rl");
		compress_rl(szSrc, szDest);
		strcpy(szSrc, szDest);
		strcat(szDest, ".ke");
		compress_ke(szSrc, szDest);
		remove(szSrc);
	}
	if(nCompress_type == 6){
		strcat(szDest, ".nc");
		compress_nc(szSrc, szDest);
		strcpy(szSrc, szDest);
		strcat(szDest, ".ke");
		compress_ke(szSrc, szDest);
		remove(szSrc);
	}
	if(nCompress_type == 7){
		strcat(szDest, ".nc");
		compress_nc(szSrc, szDest);
		strcpy(szSrc, szDest);
		strcat(szDest, ".rl");
		compress_rl(szSrc, szDest);
		remove(szSrc);
		strcpy(szSrc, szDest);
		strcat(szDest, ".ke");
		compress_ke(szSrc, szDest);
		remove(szSrc);
	}
	return 0;
}
