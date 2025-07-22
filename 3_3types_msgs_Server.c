#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/neutrino.h>
typedef struct { int type; int value; } message_t;
int main(void) {
int chid = ChannelCreate(0);
if (chid == -1) {
perror("ChannelCreate");
return EXIT_FAILURE;
}
printf("Server PID = %d, CHID = %d\n", getpid(), chid);
while (1) {
message_t msg;
int rcvid = MsgReceive(chid, &msg, sizeof(msg), NULL);
if (rcvid == -1) {
perror("MsgReceive");
continue;
}
printf("Server got: type=%d value=%d\n", msg.type, msg.value);
int reply = msg.value + 1;
MsgReply(rcvid, 0, &reply, sizeof(reply));
}
}
