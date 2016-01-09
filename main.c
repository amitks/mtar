/*******************************************************\
 * **
 * ** Filename : main.c
 * **
 * ** Description : main function.
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

int main( int argc, char *argv[] ) {
	
	char szDir_path[PATH_LENGTH];
	int nCompress_type = 0; 	
	if( argc == 2 ) {
		decompress_dir(argv[1])	;
	}
	if( argc == 3 ) {
		strcpy( szDir_path, argv[2] );
		if( strcmp( argv[1], "-nc" ) == 0 )	{
			nCompress_type = 1;
			compress_dir( szDir_path, nCompress_type );
		}
		else if( strcmp(argv[1], "-rl") == 0 )	{
			nCompress_type = 2;
			compress_dir( szDir_path, nCompress_type );
		}
		else if( strcmp(argv[1], "-ke") == 0 )	{
			nCompress_type = 3;
			compress_dir( szDir_path, nCompress_type );
		}
		else
			fprintf( stdout, "INVALID INPUT!\n" );
	}
	if( argc == 4 ) {		
		strcpy( szDir_path, argv[3] );
		if(( strcmp( argv[1], "-nc" ) == 0 ) && ( strcmp( argv[2], "-rl" ) == 0  )) {
			nCompress_type = 4;
			compress_dir( szDir_path, nCompress_type );
		}
		else if(( strcmp( argv[1], "-rl") == 0 ) && ( strcmp( argv[2], "-ke" ) == 0 )) {
			nCompress_type = 5;
			compress_dir( szDir_path, nCompress_type );
		}
		else if(( strcmp( argv[1], "-nc" ) == 0) && ( strcmp( argv[2], "-ke" ) == 0 )) {
			nCompress_type = 6;
			compress_dir( szDir_path, nCompress_type );
		}else
			fprintf( stdout, "INVALID INPUT!\n" );

	}

	if( argc == 5 ) {		
		strcpy( szDir_path, argv[4] );
		if(( strcmp( argv[1], "-nc") == 0) && (strcmp(argv[2], "-rl") == 0) && (strcmp( argv[3], "-ke" ) == 0 )) {
			nCompress_type = 7;
			compress_dir( szDir_path, nCompress_type );
		}
		else
			fprintf( stdout, "INVALID INPUT!\n" );
	}
	if( (argc < 2) || (argc > 5) )
		fprintf( stdout, "INVALID INPUT!\n" );

	free( g_pstrBUFF );
	free( g_pstrTmp_val );
	free( g_pstrToken_val );
	free( g_pstrData_val );
	return 0;
}
