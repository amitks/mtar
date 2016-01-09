/*******************************************************\
 * **
 * ** Filename : compress_rl.c
 * **
 * ** Description : Compressing any series of four or more repeating characters. The characters are replaced with a 
 *    compression code, one of the characters, and a value that represents the number of characters to repeat.
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

int compress_rl(char *pstrFile_src, char *pstrFile_dest){
	int nLen;
	int nRead;
	int nCount3;
	int nCount4;
	FILE *fp_src = fopen(pstrFile_src, "r");
	if(fp_src == NULL) return EXIT_FAILURE;
	FILE *fp_dest = fopen(pstrFile_dest, "w");
	if(fp_src == NULL) return EXIT_FAILURE;
	printf("RL COMPRESS ## FILE = %s\n", pstrFile_src);
	while ((nRead = getline(&g_pstrBUFF, &nLen, fp_src)) != -1) {
		int nCount1 = 0;
		int nCount2 = 0;
		g_pstrData = malloc(nRead*sizeof(int *));
		g_pFreq = malloc(nRead*sizeof(char *));
		
		for(nCount4=0 ; nCount4<nRead ; nCount4++)
			g_pFreq[nCount4] = 0;
		
		while( nCount1 < strlen(g_pstrBUFF) ){
			if ( strchr(g_pstrBUFF, g_pstrBUFF[nCount1]) != NULL )
			{  
				if(g_pstrBUFF[nCount1] == g_pstrBUFF[nCount1-1]) {
					g_pFreq[nCount2-1] ++ ; 
					nCount1++ ; 
				}
				else {
					g_pstrData[nCount2] = g_pstrBUFF[nCount1] ;
					g_pFreq[nCount2] ++ ;
					nCount1++;
					nCount2++;
				}	
			}
		}
		for( nCount1= 0 ; nCount1< nCount2 ; nCount1++ ) {
			if( !isdigit( g_pstrData[nCount1] )) {

				if( g_pFreq[nCount1] < 4) {
					for( nCount3 = 0; nCount3 < g_pFreq[nCount1] ; nCount3++ ) {
						if(g_pstrData[nCount1] == '\\')	g_pstrData[nCount1] = (char)224;
						fprintf(fp_dest, "%c", g_pstrData[nCount1]);
					}
				}
				else	{
					if( g_pstrData[nCount1] == '\\')
						g_pstrData[nCount1] = (char)224;
					fprintf(fp_dest, "%d%c", g_pFreq[nCount1], g_pstrData[nCount1]);
				}
			}
			else {
				for( nCount3 = 0; nCount3 < g_pFreq[nCount1] ; nCount3++ )
					fprintf( fp_dest, "\\%c", g_pstrData[nCount1] );
			}
		}
		free( g_pstrData );
		free( g_pFreq );  
	}
	fclose( fp_src );
	fclose( fp_dest );
	return 0;
}
