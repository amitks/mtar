/*******************************************************\
 * **
 * ** Filename
 * **
 * ** Description
 * **
 * ** 
 * ** Copyright (c) <date> <company>
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
int decompress_rl( char * pstrFile_src, char* pstrFile_dest ) {
	FILE *fp_src = fopen(pstrFile_src, "r");
	FILE *fp_dest = fopen(pstrFile_dest, "w");
	int nSize = 0;
	int nRead;
	int nInit_val = 10;
	printf("RL DECOMPRESS ## FILE = %s\n", pstrFile_src);
	while((nRead = getline(&g_pstrBUFF, &nSize, fp_src)) != -1) {
		int nCount1 = 0;
		while( nCount1 < strlen(g_pstrBUFF )) {
			if( isdigit(g_pstrBUFF[nCount1+1]) && (g_pstrBUFF[nCount1] == '\\' )) {
				fprintf(fp_dest, "%c", g_pstrBUFF[nCount1+1]);
				nCount1 = nCount1 + 2;
			}
			else {
				if( isdigit(g_pstrBUFF[nCount1] ) ) {
					int nCount2 = 0;
					int nVal = 0;
					int nPopval = 0;
					STACK *pStk = stack_init( nInit_val );				
					while( isdigit( g_pstrBUFF[nCount1] ) ) 
						push( pStk, (int)g_pstrBUFF[nCount1++]-48 );
					while(( nPopval = pop(pStk)) >= 0 ) 
						nVal = nVal + nPopval  * (int)pow( 10, nCount2++ );
					stack_cleanup( pStk ) ;
					for( nCount2 = 0; nCount2 < nVal-1; nCount2++ ) { 
						if( g_pstrBUFF[nCount1] == (char)224 )	g_pstrBUFF[nCount1] = '\\';
						fprintf( fp_dest, "%c", g_pstrBUFF[nCount1] );
					}
				}
				else {	
					if( g_pstrBUFF[nCount1] == (char)224 )	g_pstrBUFF[nCount1] = '\\';
					fprintf( fp_dest, "%c", g_pstrBUFF[nCount1] ); 
					nCount1++;
				} 
			}
		}
	}
	fclose( fp_src );
	fclose( fp_dest );
	return 0;
}
