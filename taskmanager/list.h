//list header file for list functions

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include "date.h"

typedef char* String;

typedef struct{
    int year;
    int month;
    int day;
}Date;

typedef struct listNode {
    String name;
    String category;
    String status;
    Date duedate;
    struct listNode* next;
}*ListNodePtr;

typedef struct list {
    ListNodePtr head;
}TaskList;

TaskList new_TaskList();

void insert(TaskList *ptr, String name, String category, String status, int day, int month, int year);
void reverselist(TaskList *ptr);
void sortbydate(TaskList *ptr);
void sortbycategory(TaskList *ptr);
void printList(TaskList *ptr);
void removeTask(TaskList *ptr, String taskname);
bool searchnode(TaskList *ptr, String taskname);
void updatetaskname(TaskList *ptr, String taskname, String newname);
void updatetaskcategory(TaskList *ptr, String taskname, String newcategory);
void updatetaskstatus(TaskList *ptr, String taskname, String newstatus);
void updateduedate(TaskList *ptr, String taskname, int day, int month, int year);
void swap(ListNodePtr a, ListNodePtr b);
void deletelist(TaskList *ptr);
void serialize(TaskList *ptr);

