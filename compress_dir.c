/*******************************************************\
 * **
 * ** Filename : compress_dir.c
 * **
 * ** Description : It compress the input directory.
 * **
 * ** 
 * ** Copyright (c) <20/06/2013> GNU
 * ** All Rights Reserved
 * **
 * ** Author:
 * **    Authors : AMIT KUMAR 
 * **		   
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

int compress_dir( char *pstrDir_path, int nCompress_type ) {
	
	char szSrc_file_path[PATH_LENGTH];
	char szDest_file_path[PATH_LENGTH];
	char szFile_name[PATH_LENGTH];
	char szDest_dir_path[PATH_LENGTH];
	int nSize = 0;
	strcpy( szDest_dir_path, pstrDir_path );
	
	char szSystem_arg[PATH_LENGTH] ;	
	strcpy( szSystem_arg, "ls -lR " );
	strcat( szSystem_arg, pstrDir_path ) ;
	strcat( szSystem_arg, " > file_index.dat" ) ;
	system( szSystem_arg );
	
	FILE *fp_index = fopen( "file_index.dat", "r" );
	if(fp_index == NULL) 
		return EXIT_FAILURE;
	while(( getline( &g_pstrINDEX_BUFF, &nSize, fp_index )) != -1 ) {
		
		if( strchr(g_pstrINDEX_BUFF, '/') != NULL ) {
			int nCount = 0;			
			while( g_pstrINDEX_BUFF[nCount] != ':' ) 
				szSrc_file_path[nCount] = g_pstrINDEX_BUFF[nCount++] ;  
			szSrc_file_path[nCount] = '\0';
			nCount = 0;
			if( strcmp( szSrc_file_path, szDest_dir_path ) == 0 ) {
				strcpy( szSystem_arg, "mkdir -p " );
				strcpy( szDest_file_path, szSrc_file_path ) ;
				strcat( szSystem_arg, szSrc_file_path ) ;
				strcat( szDest_file_path, ".mytar" );
				strcat( szSystem_arg, ".mytar" );
				system( szSystem_arg );
					
			}else {	
				nCount = 0;
				while( szSrc_file_path[nCount] == szDest_dir_path[nCount] ) nCount++;
			
				strcpy( szSystem_arg, "mkdir -p " );
				strcat( szSystem_arg, szDest_dir_path ) ;
				strcpy( szDest_file_path, szDest_dir_path ) ;
				strcat( szSystem_arg, ".mytar" );
				strcat( szDest_file_path, ".mytar" );
				strcat( szSystem_arg, szSrc_file_path+nCount );
				strcat( szDest_file_path, szSrc_file_path+nCount );
				system( szSystem_arg );
			}
		}		
		if( *g_pstrINDEX_BUFF == '-' ) {

			int nCount = strlen(g_pstrINDEX_BUFF );
			while( g_pstrINDEX_BUFF[nCount--] != ' ' );
			strcpy( szFile_name, g_pstrINDEX_BUFF+nCount+2 );
			compress_file( szSrc_file_path, szDest_file_path, szFile_name, nCompress_type );
		}
	}
	free( g_pstrINDEX_BUFF );
	fclose( fp_index );
	remove( "file_index.dat" );
	return 0;
}
