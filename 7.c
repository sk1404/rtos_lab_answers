#include <pthread.h>
#include <stdio.h>
int array[8] = {1,2,3,4,5,6,7,8};
void* process(void* arg) {
 int index = *(int*)arg;
 printf("Thread %d: processing %d and %d\n", index, array[index*2], array[index*2 + 1]);
 return NULL;
}
int main() {
 pthread_t threads[4];
 int ids[4];
 for (int i = 0; i < 4; i++) {
 ids[i] = i;
 pthread_create(&threads[i], NULL, process, &ids[i]);
 }
 for (int i = 0; i < 4; i++) {
 pthread_join(threads[i], NULL);
 }
 return 0;
}
