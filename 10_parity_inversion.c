#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
pthread_mutex_t mutex;
void* low_priority(void* arg) {
 pthread_mutex_lock(&mutex);
 printf("Low priority task acquired mutex\n");
 sleep(5);
 printf("Low priority task releasing mutex\n");
 pthread_mutex_unlock(&mutex);
 return NULL;
}
void* high_priority(void* arg) {
 sleep(1);
 printf("High priority task trying to acquire mutex\n");
 pthread_mutex_lock(&mutex);
 printf("High priority task acquired mutex\n");
 pthread_mutex_unlock(&mutex);
 return NULL;
}
int main() {
 pthread_mutexattr_t mattr;
 pthread_mutexattr_init(&mattr);
 pthread_mutexattr_setprotocol(&mattr, PTHREAD_PRIO_INHERIT);
 pthread_mutex_init(&mutex, &mattr);
 pthread_t low, high;
 pthread_create(&low, NULL, low_priority, NULL);
 pthread_create(&high, NULL, high_priority, NULL);
 pthread_join(low, NULL);
 pthread_join(high, NULL);
 return 0;
}
