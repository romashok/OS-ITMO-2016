#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>

const unsigned int BUF_SIZE = 1024;
const unsigned int STD_IN = 0;
const unsigned int STD_OUT = 1;

void cat(int infd, int outfd) {
	char buf[BUF_SIZE];
	ssize_t received = 0;
	while ((received = read(infd, buf, BUF_SIZE)) > 0) {
		ssize_t parcel = 0;
		while (parcel < received) {
			ssize_t cur = write(outfd, buf + parcel, received - parcel);
			if (cur >= 0) {
				parcel += cur;	
			} else {
				fprintf(stderr, "Writing error occured:\n%s\n", strerror(errno));	
				return;
			}
		}
	}

	if (received < 0) {
		fprintf(stderr, "Reading error occured:\n%s\n", strerror(errno));
		return;
	}
}

int main(int argc, char** argv) {
	if (argc > 1) {
		int infd = open(argv[1], O_RDONLY);
		cat(infd, STD_OUT);
		close(infd);
	} else {
		cat(STD_IN, STD_OUT);
	}
	return 0;
}
