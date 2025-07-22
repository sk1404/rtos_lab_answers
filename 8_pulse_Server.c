#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/neutrino.h>
#include <sys/dispatch.h>
#include <string.h>
#define PULSE_CODE_ONE _PULSE_CODE_MINAVAIL + 1
#define PULSE_CODE_TWO _PULSE_CODE_MINAVAIL + 2
int main() {
 int chid;
 struct _pulse pulse;
 // Create a channel
 chid = ChannelCreate(0);
 if (chid == -1) {
 perror("ChannelCreate");
 exit(EXIT_FAILURE);
 }
 printf("Server PID: %d, Channel ID: %d\n", getpid(), chid);
 // Wait for pulses
 while (1) {
 int rc = MsgReceive(chid, &pulse, sizeof(pulse), NULL);
 if (rc == -1) {
 perror("MsgReceive");
 continue;
 }
 if (pulse.code == PULSE_CODE_ONE) {
 printf("Received Pulse: CODE_ONE, Value: %d\n", pulse.value.sival_int);
 } else if (pulse.code == PULSE_CODE_TWO) {
 printf("Received Pulse: CODE_TWO, Value: %d\n", pulse.value.sival_int);
 } else {
 printf("Received Unknown Pulse: code=%d, value=%d\n", pulse.code,
pulse.value.sival_int);
 }
 }
 ChannelDestroy(chid);
 return 0;
 }
