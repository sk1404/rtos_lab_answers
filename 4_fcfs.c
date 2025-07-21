#include <stdio.h>
#include "tcb.h"
int main() {
 TaskControlBlock tasks[3] = {
 {1, 0, 0, 3, 0},
 {2, 0, 1, 6, 0},
 {3, 0, 2, 4, 0}
 };
 int time = 0;
  for (int i = 0; i < 3; i++) {
  printf("Task %d starts at %d\n", tasks[i].task_id, time);
  time += tasks[i].execution_time;
  printf("Task %d ends at %d\n", tasks[i].task_id, time);
  }
  return 0;
 }
