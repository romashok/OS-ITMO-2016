#include <signal.h>
#include <unistd.h>
#include <stdio.h>

char already_handled = 0;

void sig_handler(int signum, siginfo_t* siginfo, void* context) {
	if(!already_handled) {
		already_handled = 1;
		printf("SIGUSR%d from %d\n", signum == SIGUSR1 ? 1 : 2, siginfo->si_pid);	
	}

}

int main() {
	struct sigaction action;
	action.sa_sigaction = sig_handler;
	action.sa_flags = SA_SIGINFO;
	
	if (sigemptyset(&action.sa_mask) != 0 
		|| sigaddset(&action.sa_mask, SIGUSR1) != 0
		|| sigaddset(&action.sa_mask, SIGUSR2) != 0) {
		perror("Some error occured!\n");
	}

	if ((sigaction(SIGUSR1, &action, NULL))
		|| sigaction(SIGUSR2,&action, NULL)) {
		perror("Can`t set sig_hanflers\n");
		}
	
	sleep(10);
	if (!already_handled) {
		printf("No signals were caught\n");
	}
	return 0;
}
