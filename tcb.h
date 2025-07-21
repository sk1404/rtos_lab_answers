// tcb.h
#ifndef TCB_H
#define TCB_H
typedef struct {
int task_id;
int priority;
int arrival_time;
int execution_time;
int deadline;
} TaskControlBlock;
#endif
