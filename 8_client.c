#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/neutrino.h>
#include <string.h>
#define PULSE_CODE_ONE _PULSE_CODE_MINAVAIL + 1
#define PULSE_CODE_TWO _PULSE_CODE_MINAVAIL + 2
int main(int argc, char *argv[]) {
 if (argc != 3) {
 printf("Usage: %s <server_pid> <channel_id>\n", argv[0]);
 return EXIT_FAILURE;
 }
 int server_pid = atoi(argv[1]);
 int chid = atoi(argv[2]);
 int coid;
 coid = ConnectAttach(0, server_pid, chid, _NTO_SIDE_CHANNEL, 0);
 if (coid == -1) {
 perror("ConnectAttach");
 exit(EXIT_FAILURE);
 }
 // Send first pulse
 if (MsgSendPulse(coid, SIGEV_PULSE_PRIO_INHERIT, PULSE_CODE_ONE, 100) ==
-1) {
 perror("MsgSendPulse - CODE_ONE");
 } else {
 printf("Sent PULSE_CODE_ONE with value 100\n");
 }
 // Send second pulse
 if (MsgSendPulse(coid, SIGEV_PULSE_PRIO_INHERIT, PULSE_CODE_TWO, 200)
== -1) {
 perror("MsgSendPulse - CODE_TWO");
 } else {
	 printf("Sent PULSE_CODE_TWO with value 200\n");
	  }
	  ConnectDetach(coid);
	  return 0;
	  }
