//write a c program with the following features:
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <fcntl.h>

//catch the following signals 
static void sighandler(int signo) {
	//SIGINT
		//before exciting, append a msg to a file noting that the prog exited due to SIGINT
		//to make program quit, look up the exit fxn
	if(signo == SIGINT) {
		char error[100] = "File exited due to SIGNINT\n";
		int file = open("log.txt", O_WRONLY | O_CREAT | O_APPEND, 0644);
		write(file, error, sizeof(error));
		close(file);
		exit(0);
	}
	//SIGUSR1
		//print out the pid of the parent process
		//should not cause the program to exit
	if(signo == SIGUSR1) {
		printf("ppid: %d\n", getppid());
	}
}
	
int main() {
	signal(SIGINT, sighandler);
	signal(SIGUSR1, sighandler);
	//runs constantly inside a forever while loop
	while(1) {
		//print out the process pid inside the loop
		printf("pid: %d\n", getpid());
		//use sleep(1) fxn to have the program wait 1 section between inner loop iterations
		sleep(1);
	}
	return 0;
}
		
