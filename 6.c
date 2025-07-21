#include <stdio.h>
#include "tcb.h"
int main() {
 TaskControlBlock tasks[4] = {
 {1, 0, 0, 4, 6},
 {2, 0, 2, 2, 5},
 {3, 0, 4, 1, 6},
 {4, 0, 5, 5, 10}
 };
 // Sort by deadline
 for (int i = 0; i < 3; i++)
 for (int j = i + 1; j < 4; j++)
 if (tasks[i].deadline > tasks[j].deadline) {
 TaskControlBlock tmp = tasks[i];
 tasks[i] = tasks[j];
 tasks[j] = tmp;
 }
 int time = 0;
 for (int i = 0; i < 4; i++) {
 printf("Task %d starts at %d, ends at %d\n", tasks[i].task_id, time, time +
tasks[i].execution_time);
 time += tasks[i].execution_time;
 }
 return 0;
}
