#ifndef _IO_H
#define _IO_H

#define STDOUT 1

class OutputStream{
public:
	virtual int write(const char* buf, int len){};
};

class FileOutputStream: public OutputStream{
private:
	int fd;
public:
	FileOutputStream(int fileDescriptor):fd(fileDescriptor){}
	virtual int write(const char* buf, int len);
};

class ConsoleOutputStream: public FileOutputStream{
public:
	ConsoleOutputStream():FileOutputStream(STDOUT){}
};

class OutputWriter{
protected:
	OutputStream* stream;
public:
	OutputWriter(OutputStream* st): stream(st){}
	void print(const char* string);
	void println(const char* string);
};

class FileOutputWriter: public OutputWriter{
public:
	FileOutputWriter(int fileDescriptor):OutputWriter(0){
		stream = new FileOutputStream(fileDescriptor);
	}
	
	~FileOutputWriter(){
		delete stream;
	}
};

class ConsoleOutputWriter: public FileOutputWriter{
public:
	ConsoleOutputWriter():FileOutputWriter(STDOUT){}
};

#endif
