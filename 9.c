#include <stdio.h>
#include "tcb.h"
int main() {
 TaskControlBlock tasks[4] = {
 {1, 0, 0, 4, 0},
 {2, 0, 2, 2, 0},
 {3, 0, 4, 1, 0},
 {4, 0, 5, 5, 0}
 };
 // Sorting by execution time (shorter = higher priority)
 for (int i = 0; i < 3; i++)
 for (int j = i + 1; j < 4; j++)
 if (tasks[i].execution_time > tasks[j].execution_time) {
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
