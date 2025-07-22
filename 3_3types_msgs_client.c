#include <stdio.h>
#include <stdlib.h>
#include <sys/neutrino.h>
#include <sys/netmgr.h>
typedef struct { int type; int value; } message_t;
int main(int argc, char *argv[]) {
if (argc != 3) {
	fprintf(stderr, "Usage: %s <server_pid> <channel_id>\n", argv[0]);
	return EXIT_FAILURE;
	}
	pid_t server_pid = atoi(argv[1]);
	int server_chid = atoi(argv[2]);
	int coid = ConnectAttach(ND_LOCAL_NODE, server_pid, server_chid, 0, 0);
	if (coid == -1) {
	perror("ConnectAttach");
	return EXIT_FAILURE;
	}
	for (int i = 1; i <= 3; ++i) {
	message_t msg = { .type = i, .value = i * 100 };
	int reply;
	printf("Client sending type=%d value=%d\n", msg.type, msg.value);
	if (MsgSend(coid, &msg, sizeof(msg), &reply, sizeof(reply)) == -1) {
	perror("MsgSend");
	ConnectDetach(coid);
	return EXIT_FAILURE;
	}
	printf("Client got reply: %d\n", reply);
	}
	ConnectDetach(coid);
	return EXIT_SUCCESS;
	}


