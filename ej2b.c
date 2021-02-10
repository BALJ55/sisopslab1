#include <stdio.h>
#include <unistd.h>

int main(int argc,char** argv){
	int fd = open(argv[1], O_RDONLY);
	int len = lseek(fd,0,SEEK_END);
	void *data = mmap(0,len, PROT_READ, MAP_PRIVATE, fd,0);
	int nuevoFD = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR |S_IRGP|S_IROTH);
	if(nuevoFD < 0){
		return -1;
	}
	if(write(nuevoFD,data,len) != len){
		printf("error al escribir");
		return -1;
	}

	return 0;
}
