#include "list.h"

TaskList new_TaskList() {
    TaskList temp;
    temp.head = NULL;
    return temp;
}

//this function can be called to reverese the supplied task list
void reverselist(TaskList *ptr){
    //initialise current, previous and next pointer
    ListNodePtr current = ptr->head;
    ListNodePtr prev, next = NULL;

    while(current != NULL){
        //store next
        next = current->next;
        //reverse current node's pointer
        current->next = prev;
        //move pointers one position ahead
        prev = current;
        current = next;
    }
    ptr->head = prev;
}

//insert item at the beginning of the list
void insert(TaskList *ptr, String name, String category, String status, int day, int month, int year){
    //initilialize the new task with all its data
    ListNodePtr current = ptr->head;
    ListNodePtr new_node = malloc(sizeof * new_node);
    new_node->name = (char *)malloc(strlen(name)+1);
    strcpy(new_node->name, name);
    new_node->category = (char *)malloc(strlen(category)+1);
    strcpy(new_node->category, category);
    new_node->status = (char *)malloc(strlen(status)+1);
    strcpy(new_node->status, status);
    new_node->duedate.day = day;
    new_node->duedate.month = month;
    new_node->duedate.year = year;

    //make the head item the next item of the next node
    new_node->next = current;

    //make the new node the head of the task list
    ptr->head = new_node;
}

//remove given task from the list
void removeTask(TaskList *ptr, String taskname){
    //store head of list in current; create previous node
    ListNodePtr current = ptr->head;
    ListNodePtr prev;

    //if the head item contains the given taskname, delete the task
    //deallocate dynamic memory using free
    if(current != NULL && (strcmp(current->name, taskname) == 0)){
        ptr->head = current->next; //change head of list
        free(current->name);
        free(current->category);
        free(current->status);
        free(current);
        printf("Task deleted successfully\n");
        return;
    }

    //Search for the task to be deleted, while keeping track of the
    //previous node that needs to be changed
    while(current != NULL && (strcmp(current->name, taskname) != 0)){
        prev = current;
        current = current -> next;
    }

    //if task is not present, notify the user
    if(current == NULL){
        printf("No such task found\n");
        return;
    }

    //remove task upon finding it
    prev->next = current->next;
    free(current->name);
    free(current->category);
    free(current->status);
    free(current);
    printf("Task deleted successfully\n");

}

//delete entire linked list
void deletelist(TaskList *ptr){
    ListNodePtr current = ptr->head;
    while(current != NULL){
        ListNodePtr empty = current;
        current = current->next;
        free(&empty->name);
        free(&empty->category);
        free(&empty->status);
        free(empty);
    }
    ptr->head = NULL;
}


void updatetaskname(TaskList *ptr, String taskname, String newname){
    //store head of list in current; create previous node
    ListNodePtr current = ptr->head;

    //if the head item contains the given taskname, update the name with the new name
    if(current != NULL && (strcmp(current->name, taskname) == 0)){
        current->name = (char *)malloc(strlen(newname)+1);
        strcpy(current->name, newname);
        return;
    }

    //Search for the task to be updated
    while(current != NULL && (strcmp(current->name, taskname) != 0)){
        current = current -> next;
    }

    //if task is not present, notify the user
    if(current == NULL){
        printf("No such task found\n");
        return;
    }

    //update task upon finding it
    current->name = (char *)malloc(strlen(taskname)+1);
    strcpy(current->name, newname);
    printf("Task name updated successfully\n");

}

void updatetaskcategory(TaskList *ptr, String taskname, String newcategory){
    //store head of list in current; create previous node
    ListNodePtr current = ptr->head;

    //if the head item contains the given taskname, update the name with the new name
    if(current != NULL && (strcmp(current->name, taskname) == 0)){
        current->category = (char *)malloc(strlen(newcategory)+1);
        strcpy(current->category, newcategory);
        return;
    }

    //Search for the task to be updated
    while(current != NULL && (strcmp(current->name, taskname) != 0)){
        current = current -> next;
    }

    //if task is not present, notify the user
    if(current == NULL){
        printf("No such task found\n");
        return;
    }

    //update task upon finding it
    current->category = (char *)malloc(strlen(newcategory)+1);
    strcpy(current->category, newcategory);
    printf("Task category updated successfully\n");

}

void updatetaskstatus(TaskList *ptr, String taskname, String newstatus){
    //store head of list in current; create previous node
    ListNodePtr current = ptr->head;

    //if the head item contains the given taskname, update the name with the new name
    if(current != NULL && (strcmp(current->name, taskname) == 0)){
        current->status = (char *)malloc(strlen(newstatus)+1);
        strcpy(current->status, newstatus);
        return;
    }

    //Search for the task to be updated
    while(current != NULL && (strcmp(current->name, taskname) != 0)){
        current = current -> next;
    }

    //if task is not present, notify the user
    if(current == NULL){
        printf("No such task found\n");
        return;
    }

    //update task upon finding it
    current->status = (char *)malloc(strlen(newstatus)+1);
    strcpy(current->status, newstatus);
    printf("Task status updated successfully\n");

}

void updateduedate(TaskList *ptr, String taskname, int day, int month, int year){
    //store head of list in current; create previous node
    ListNodePtr current = ptr->head;

    //if the head item contains the given taskname, update the name with the new name
    if(current != NULL && (strcmp(current->name, taskname) == 0)){
        current->duedate.day = day;
        current->duedate.month = month;
        current->duedate.year = year;
        return;
    }

    //Search for the task to be updated
    while(current != NULL && (strcmp(current->name, taskname) != 0)){
        current = current -> next;
    }

    //if task is not present, notify the user
    if(current == NULL){
        printf("No such task found\n");
        return;
    }

    //update task upon finding it
    current->duedate.day = day;
    current->duedate.month = month;
    current->duedate.year = year;
    printf("Task duedate updated successfully\n");

}



//sort the supplied task list in ascending order of task due date
void sortbydate(TaskList *ptr){

    int swapped;
    ListNodePtr first;
    ListNodePtr last = NULL;

    //check if list is empty
    if(ptr->head == NULL){
        return;
    }

    do{
        swapped = 0;
        first = ptr->head;
        while(first->next != last){
            //swap the node data if the later node has an earlier duedate
            if(is_earlier(first->next->duedate.day, first->next->duedate.month, first->next->duedate.year,
                           first->duedate.day, first->duedate.month, first->duedate.year)){
                            swap(first, first->next);
                            swapped = 1;
                           }
                           first = first->next;
        }
        last = first;
    }while(swapped);
}

//sort the supplied task list in ascending order of category
void sortbycategory(TaskList *ptr){
    int swapped;
    ListNodePtr first;
    ListNodePtr last = NULL;

    //check if list is empty
    if(ptr->head == NULL){
        return;
    }
    do{
        swapped = 0;
        first = ptr->head;
        while(first->next != last){
            //swap node data if the later node has a lower value string
            if(strcmp(first->category, first->next->category) > 0){
                            swap(first, first->next);
                            swapped = 1;
                           }
                           first = first->next;
        }
        last = first;
    }while(swapped);
}

//swap the content of the supplied nodes
void swap(ListNodePtr a, ListNodePtr b){

    //copy data into temp variables
    String tempname[100];
    String tempcategory[100];
    String tempstatus[100];
    strcpy(tempname, a->name);
    strcpy(tempcategory, a->category);
    strcpy(tempstatus, a->status);
    int tempday = a->duedate.day;
    int tempmonth = a->duedate.month;
    int tempyear = a->duedate.year;

    //put data of second node into first node; resize to accomodate new string
    a->name = (char *)malloc(strlen(b->name)+1);
    a->category = (char *)malloc(strlen(b->category)+1);
    a->status = (char *)malloc(strlen(b->status)+1);
    strcpy(a->name, b->name);
    strcpy(a->category, b->category);
    strcpy(a->status, b->status);
    a->duedate.day = b->duedate.day;
    a->duedate.month = b->duedate.month;
    a->duedate.year = b->duedate.year;

    //put temp data in the second node and complete the swap
    b->name = (char *)malloc(strlen(tempname)+1);
    b->category = (char *)malloc(strlen(tempcategory)+1);
    b->status = (char *)malloc(strlen(tempstatus)+1);
    strcpy(b->name, tempname);
    strcpy(b->category, tempcategory);
    strcpy(b->status, tempstatus);
    b->duedate.day = tempday;
    b->duedate.month = tempmonth;
    b->duedate.year = tempyear;
}

//search for a given task in a list
bool searchnode(TaskList *ptr, String taskname){
    ListNodePtr current = ptr->head;

    //search for the node that containes the supplied data
    while(current != NULL){
        if((strcmp(current->name, taskname) == 0)){
            //return true upon a successful find
            return true;
        }
        //traverse list
        current = current->next;
    }
    //return false if data is not found in the list
    return false;
}


//print the list from the head till the null pointer i.e end of the list
void printList(TaskList *ptr){
    //store head of Task list
    ListNodePtr current = ptr->head;
    //traverse untill the end of the list while printing all its content
    while(current != NULL){
        printf("Task Name: ");
        printf("%s\n", current->name);
        printf("Task Category: ");
        printf("%s\n", current->category);
        printf("Task Status: ");
        printf("%s\n", current->status);
        printf("Task Due Date: ");
        printf("%02d", current->duedate.day);
        printf("/");
        printf("%02d", current->duedate.month);
        printf("/");
        printf("%02d\n", current->duedate.year);
        printf(" \n");
        current = current->next;
    }
    printf("\n");
}

//output the content of the list to a textfile
void serialize(TaskList *ptr){
    //open the file
    FILE* file = fopen("output.txt", "w");
    if(file == NULL){
        exit(1);
    }
    //Go through each node of the linked list and write content of each field to the text file
    for(ListNodePtr current = ptr->head; current != NULL; current = current->next){
        fprintf(file, "%s\n", current->name);
        fprintf(file, "%s\n", current->category);
        fprintf(file, "%s\n", current->status);
        fprintf(file, "%02d/", current->duedate.day);
        fprintf(file, "%02d/", current->duedate.month);
        fprintf(file, "%d\n", current->duedate.year);
    }
    //close the file
    fclose(file);
}
