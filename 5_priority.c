#include <stdio.h>
#include "tcb.h"
int main() {
 TaskControlBlock tasks[3] = {
 {1, 2, 0, 3, 0},
 {2, 1, 0, 4, 0},
 {3, 3, 0, 2, 0}
 };
 for (int i = 0; i < 2; i++)
 for (int j = i + 1; j < 3; j++)
 if (tasks[i].priority > tasks[j].priority) {
 TaskControlBlock temp = tasks[i];
 tasks[i] = tasks[j];
 tasks[j] = temp;
 }
 int time = 0;
 for (int i = 0; i < 3; i++) {
 printf("Task %d starts at %d\n", tasks[i].task_id, time);
 time += tasks[i].execution_time;
 printf("Task %d ends at %d\n", tasks[i].task_id, time);
 }
 return 0;
}
