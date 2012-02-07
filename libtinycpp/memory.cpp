char* buf[1000];

void* operator new(unsigned long size){
		return (void*)buf;
}

void operator delete(void* data){
	
}



