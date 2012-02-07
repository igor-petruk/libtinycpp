#include "io.h"

#define BUF_SIZE 20

int FileOutputStream::write(const char* buf, int len){
	int result;
	asm volatile (
		"mov $1, %%eax\n\t syscall\n\t"
		: "=a" (result)
		: "D"(fd),"S"(buf), "d"(len)
		: "%rcx","%r11");

	return result;
}

void OutputWriter::print(const char* string){
	int length = 0;
	while (string[length]!=0){
		length++;
	}
	stream->write(string, length);	
}

void OutputWriter::println(const char* string){
	print(string);
	print("\n");
}


/*void write_long(long i){
	if (i!=0){
		char buf[BUF_SIZE]={0};
		int offset = BUF_SIZE;
		while(i!=0){
			buf[--offset] = '0'+(i%10);
			i/=10;
		}
		write(STDOUT,buf+offset,BUF_SIZE-offset);
	}else{
		write(STDOUT,"0",1);
	}
}

void write_string(char* str){
	int length = 0;
	while (str[length]!=0){
		length++;
	}
	write(STDOUT, str, length);
}

*/

