mytar: main.o compress_nc.o compress_rl.o compress_ke.o stack.o decompress_rl.o decompress_nc.o decompress_ke.o replace_token.o replace_word.o compress_file.o compress_dir.o decompress_file.o decompress_dir.o
	gcc -o mytar main.o compress_nc.o compress_rl.o compress_ke.o stack.o decompress_rl.o decompress_nc.o decompress_ke.o replace_token.o replace_word.o compress_file.o compress_dir.o decompress_file.o decompress_dir.o mytar.h -lm 
main.o:main.c
	gcc -c -g main.c mytar.h
compress_nc.o:compress_nc.c
	gcc -c -g compress_nc.c mytar.h
compress_rl.o:compress_rl.c
	gcc -c -g compress_rl.c mytar.h
compress_ke.o:compress_ke.c
	gcc -c -g compress_ke.c mytar.h
stack.o:stack.c
	gcc -c -g stack.c mytar.h
decompress_rl.o:decompress_rl.c
	gcc -c -g decompress_rl.c mytar.h
decompress_nc.o:decompress_nc.c
	gcc -c -g decompress_nc.c mytar.h
decompress_ke.o:decompress_ke.c
	gcc -c -g decompress_ke.c mytar.h
replace_token.o:replace_token.c
	gcc -c -g replace_token.c mytar.h
replace_word.o:replace_word.c
	gcc -c -g replace_word.c mytar.h
compress_file.o:compress_file.c
	gcc -c -g compress_file.c mytar.h
compress_dir.o:compress_dir.c
	gcc -c -g compress_dir.c mytar.h
decompress_file.o:decompress_file.c
	gcc -c -g decompress_file.c mytar.h
decompress_dir.o:decompress_dir.c
	gcc -c -g decompress_dir.c mytar.h

clean:
	rm -rf *.o
