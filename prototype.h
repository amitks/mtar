#ifndef PROTOTYPE_H
#define PROTOTYPE_H

int compress_file(char *, char *, char *, int );
int compress_dir(char *, int );
int decompress_file(char *, char *, char * );
int decompress_dir(char *);
int compress_nc(char *, char *);
int compress_rl(char *, char *);
int compress_ke(char *, char *);
int decompress(char *);
int decompress_nc(char *, char *);
int decompress_rl(char *, char *);
int decompress_ke(char *, char *);
char * replace_word(char *);
char * replace_token(char *);
STACK * stack_init(int );

#endif
