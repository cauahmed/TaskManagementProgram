#include "date.h"
#include "list.h"

int main()
{
    //variables to store data that will be required for carrying out all the menu operations
    char nameholder[100];
    char newdata[100];
    char categoryholder[100];
    char statusholder[100];
    int day, month, year;
    TaskList TaskHolder = new_TaskList();
    int initiator = 1;
    bool valid = false;
    int subinitiator = 0;

    while(initiator){
        //initialises the main menu
        printf("Personal Task Management\n");
        printf("1) Add New Task\n");
        printf("2) View All Tasks; Ascending Order of duedate\n");
        printf("3) Update Task\n");
        printf("4) Delete Task\n");
        printf("5) Output TaskList\n");
        printf("6) Exit Program\n");

        printf("Enter option:\n");

        scanf_s("%d", &initiator);
        /*getchar() is used multiple times to return the new line character after each scanf input so
        the gets method dont take the new line as their input*/
        getchar();
        //starts the program
        switch(initiator) {

        case 1:
                //validates task name
                while(valid == false){
                    printf("Please enter task name\n");
                    gets(nameholder);
                    if(strlen(nameholder) > 20){
                        printf("Task name is invalid; Please enter a task with a maximum of 20 characters\n");
                    }else{
                        valid = true;
                    }
                }
                //switch is reset in this statement for validating the next field
                valid = false;

                //validates task category
                while(valid == false){
                    printf("Please enter task category\n");
                    gets(categoryholder);
                    if(strlen(categoryholder) > 15){
                        printf("Category is invalid; Please enter a task category with a maximum of 15 characters\n");
                    }else{
                        valid = true;
                    }
                }

                valid = false;

                //validates task status
                while(valid == false){
                    printf("Please enter task status\n");
                    gets(statusholder);
                    if(strlen(statusholder) > 15){
                        printf("Status is invalid; Please enter a task status with a maximum of 15 characters\n");
                    }else{
                        valid = true;
                    }
                }

                valid = false;
                //validates task due date
                while(valid == false){
                    printf("Please enter task due day\n");
                    scanf_s("%d", &day);
                    getchar();
                    printf("Please enter task due month\n");
                    scanf_s("%d", &month);
                    getchar();
                    printf("Please enter task due year\n");
                    scanf_s("%d", &year);
                    getchar();
                    if(check_date(day, month, year) != 1){
                        printf("The entered duedate is invalid; Please enter a valid duedate\n");
                    }else{
                        valid = true;
                    }
                }
                //inserts task into lits after succcessful validation of all fields
                insert(&TaskHolder, &nameholder, &categoryholder, &statusholder, day, month, year);
                printf("The task was added successfully\n");
                valid = false;
                break;

        case 2:
                //sorts task list by date and prints the list to screen
                sortbydate(&TaskHolder);
                printList(&TaskHolder);
                break;

        case 3:
                //initiates sub menu for updating existing item
                printf("Please choose what you would like to update\n");
                printf("1) Update name\n");
                printf("2) Update category\n");
                printf("3) Update status\n");
                printf("4) Update duedate\n");
                printf("5) Go back\n");

                printf("Enter option:\n");

                scanf_s("%d", &subinitiator);
                getchar();

                //validates and updates task name
                if(subinitiator == 1){
                    while(valid == false){
                        printf("Please enter existing task name\n");
                        gets(nameholder);
                        if(strcmp(nameholder, "back") == 0){
                            break;
                        }else if(searchnode(&TaskHolder, nameholder) == false){
                            printf("Task not found; Please enter another task name\n");
                        }else{
                            printf("Please enter new task name\n");
                            gets(newdata);
                                if((strlen(newdata) > 20)){
                                    printf("Task name invalid; Please enter a valid task name\n");
                                    break;
                                }else{
                                    updatetaskname(&TaskHolder, &nameholder, &newdata);
                                    printf("Task name updated successfully\n");
                                    valid = true;
                                }
                        }
                  }
                  valid = false;
                //validates and updates task category
                }else if(subinitiator == 2){
                    while(valid == false){
                        printf("Please enter existing task name\n");
                        gets(nameholder);
                        if(strcmp(nameholder, "back") == 0){
                            break;
                        }else if(searchnode(&TaskHolder, nameholder) == false){
                            printf("Task not found; Please enter another task name\n");
                        }else{
                            printf("Please enter new task category\n");
                            gets(newdata);
                                if((strlen(newdata) > 15)){
                                    printf("Task category invalid; Please enter a valid task category\n");
                                    break;
                                }else{
                                    updatetaskcategory(&TaskHolder, &nameholder, &newdata);
                                    printf("Task category updated successfully\n");
                                    valid = true;
                                }
                        }
                  }
                  valid = false;
                //validates and updates task status
                }else if(subinitiator == 3){
                    while(valid == false){
                        printf("Please enter existing task name\n");
                        gets(nameholder);
                        if(strcmp(nameholder, "back") == 0){
                            break;
                        }else if(searchnode(&TaskHolder, nameholder) == false){
                            printf("Task not found; Please enter another task name\n");
                        }else{
                            printf("Please enter new status\n");
                            gets(newdata);
                                if((strlen(newdata) > 15)){
                                    printf("Task status invalid; Please enter a valid task status\n");
                                    break;
                                }else{
                                    updatetaskstatus(&TaskHolder, &nameholder, &newdata);
                                    printf("Task status updated successfully\n");
                                    valid = true;
                                }
                        }
                  }
                  valid = false;
                //validates and updates task due date
                }else if(subinitiator == 4){
                    while(valid == false){
                        printf("Please enter existing task name\n");
                        gets(nameholder);
                        if(strcmp(nameholder, "back") == 0){
                            break;
                        }else if(searchnode(&TaskHolder, nameholder) == false){
                            printf("Task not found; Please enter another task name\n");
                        }else{
                            printf("Please enter new task due day\n");
                            scanf_s("%d", &day);
                            getchar();
                            printf("Please enter new task due month\n");
                            scanf_s("%d", &month);
                            getchar();
                            printf("Please enter new task due year\n");
                            scanf_s("%d", &year);
                            getchar();
                                if(check_date(day, month, year) != 1){
                                    printf("Task duedate invalid; Please enter a valid task duedate\n");
                                    break;
                                }else{
                                    updateduedate(&TaskHolder, &nameholder, day, month, year);
                                    printf("Task duedate updated successfully\n");
                                    valid = true;
                                }
                        }
                  }
                  valid = false;
                //returns to main menu
                }else if(subinitiator == 5){
                    break;
                }else{
                    //notifies user about invalid option an returns to main menu
                    printf("Invalid option! You will be redirected to main menu\n");
                    break;
                }
                printf("\n");
                break;
        case 4:
                //takes input from user and deletes the requested task and all its details from the list
                printf("Please enter task name to be deleted\n");
                gets(nameholder);
                removeTask(&TaskHolder, &nameholder);
                break;

        case 5:
                //serializes the data and outputs it to a text file
                serialize(&TaskHolder);
                printf("Task List has been exported successfully");
                break;

        case 6:
                //deletes the entire task list and stops the program
                deletelist(&TaskHolder);
                printf("Thank you for using the Task management system");
                return;
                break;

        default:
                //notifies the user about an invalid selection and returns them back to the main menu
                printf("Please enter a valid option\n");
        }
        printf("\n");
    }
    return 0;
}








