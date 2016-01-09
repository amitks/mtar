/*******************************************************\
 * **
 * ** Filename : decompress_file.c
 * **
 * ** Description :It decompress compressed file.
 * **
 * ** 
 * ** Copyright (c) <20/06/2013> GNU
 * ** All Rights Reserved
 * **
 * ** Author:
 * **    Authors : AMIT KUMAR 2710402
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

int decompress_file(char *pstrSrc_file_path, char *pstrDest_file_path, char *pstrFile_name ) {
	int compress_type = 0;	
	char szFile_Dest[100] ;
	char szDest[100];
	char szFile_Src[100];
	char szSrc[100];
	
	strcpy(szFile_Src, pstrSrc_file_path);
	strcat(szFile_Src, "/");
	strcat(szFile_Src, pstrFile_name);
	
	strcpy(szFile_Dest, pstrDest_file_path);
	strcat(szFile_Dest, "/");
	strcat(szFile_Dest, pstrFile_name);
	int nCount = 0;
	while(szFile_Src[nCount] != '\n') szSrc[nCount] = szFile_Src[nCount++] ;
	szSrc[nCount] = '\0';
	nCount = 0;
	while(szFile_Dest[nCount] != '\n') szDest[nCount] = szFile_Dest[nCount++] ;
	szDest[nCount] = '\0';
	
	if(strstr(pstrFile_name, ".nc") && !strstr(pstrFile_name, ".rl") && !strstr(pstrFile_name, ".ke")) {
		nCount = strlen(szDest);
		while(szDest[nCount] != '.') szDest[nCount--] = '\0'; szDest[nCount] = '\0';
		decompress_nc(szSrc, szDest);
	}

	if(!strstr(pstrFile_name, ".nc") && strstr(pstrFile_name, ".rl") && !strstr(pstrFile_name, ".ke")) {
		nCount = strlen(szDest);
		while(szDest[nCount] != '.') szDest[nCount--] = '\0'; szDest[nCount] = '\0';
		decompress_rl(szSrc, szDest);
	}
	if(!strstr(pstrFile_name, ".nc") && !strstr(pstrFile_name, ".rl") && strstr(pstrFile_name, ".ke")) {
		nCount = strlen(szDest);
		while(szDest[nCount] != '.') szDest[nCount--] = '\0'; szDest[nCount] = '\0';
		decompress_ke(szSrc, szDest);
	}
	if(strstr(pstrFile_name, ".nc") && strstr(pstrFile_name, ".rl") && !strstr(pstrFile_name, ".ke")) {
		
		nCount = strlen(szDest);
		while(szDest[nCount] != '.') szDest[nCount--] = '\0'; szDest[nCount] = '\0';
		decompress_rl(szSrc, szDest);
		strcpy(szSrc, szDest);
		nCount = strlen(szDest);
		while(szDest[nCount] != '.') szDest[nCount--] = '\0'; szDest[nCount] = '\0';
		decompress_nc(szSrc, szDest);
		remove(szSrc);
	}
	if(strstr(pstrFile_name, ".nc") && !strstr(pstrFile_name, ".rl") && strstr(pstrFile_name, ".ke")) {
		nCount = strlen(szDest);
		while(szDest[nCount] != '.') szDest[nCount--] = '\0'; szDest[nCount] = '\0';
		decompress_ke(szSrc, szDest);
		strcpy(szSrc, szDest);
		nCount = strlen(szDest);
		while(szDest[nCount] != '.') szDest[nCount--] = '\0'; szDest[nCount] = '\0';
		decompress_nc(szSrc, szDest);
		remove(szSrc);
	}
	if(!strstr(pstrFile_name, ".nc") && strstr(pstrFile_name, ".rl") && strstr(pstrFile_name, ".ke")) {
		nCount = strlen(szDest);
		while(szDest[nCount] != '.') szDest[nCount--] = '\0'; szDest[nCount] = '\0';
		decompress_ke(szSrc, szDest);
		strcpy(szSrc, szDest);
		nCount = strlen(szDest);
		while(szDest[nCount] != '.') szDest[nCount--] = '\0'; szDest[nCount] = '\0';
		decompress_rl(szSrc, szDest);
		remove(szSrc);
	}
	if(strstr(pstrFile_name, ".nc") && strstr(pstrFile_name, ".rl") && strstr(pstrFile_name, ".ke")) {
		nCount = strlen(szDest);
		while(szDest[nCount] != '.') szDest[nCount--] = '\0'; szDest[nCount] = '\0';
		decompress_ke(szSrc, szDest);
		strcpy(szSrc, szDest);
		nCount = strlen(szDest);
		while(szDest[nCount] != '.') szDest[nCount--] = '\0'; szDest[nCount] = '\0';
		decompress_rl(szSrc, szDest);
		remove(szSrc);
		strcpy(szSrc, szDest);
		nCount = strlen(szDest);
		while(szDest[nCount] != '.') szDest[nCount--] = '\0'; szDest[nCount] = '\0';
		decompress_nc(szSrc, szDest);
		remove(szSrc);
	}
	return 0;
}
