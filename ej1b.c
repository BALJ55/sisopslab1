#include <stdio.h>
#include <unistd.h>

int main(int argc,char** argv){
	
	int f = fork();
	if(f!=0){
		printf("%d\n",(int)getpid());
	}
	execl(argv[1],(char*)NULL);
	return 0;
}
