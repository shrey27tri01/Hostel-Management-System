#include "headers/function.h"


struct student * heado = NULL;
// the below is security check funtion
void security_check(void){
    char correct_password[15] = "password";//correct password
    char correct_username[15] = "username";//correct username
    char * username = malloc(15 * sizeof(char));
    char * password = malloc(15 * sizeof(char));
    while (1){
        printf("PLEASE ENTER THE USERNAME : ");
        scanf("%s",username);
        if(strcmp(username,correct_username) == 0){
            printf("\nPLEASE ENTER THE PASSWORD : ");
            password = getpass("");
            if(strcmp(password,correct_password) == 0){
                system("clear");
                printf("\nWELCOME ADMIN.\n");
                break;
            }
            else{
                printf("\nWRONG PASSWORD ! \nPLEASE ENTER THE CORRECT PASSWORD\n");
                free(password);

            }
        }
        else{
            printf("\nNO SUCH USER-NAME \nPLEASE ENTER A VALID USERNAME\n");
            free(username);

        }
    }
}   
//this is the function to delete one student
struct student * del_one_student(struct student * head,int batch,int rollnumber){
    struct student * temp, *ptemp;
    ptemp = NULL;
    int flag = 0;
    if(head == NULL){//if file is empty then it won't go into segmentation fault!
        printf("NO STUDENT EXISTS\n");
        return head;
    }
    else{
        if(head->rollnumber == rollnumber && head -> batch == batch){
            struct student * z = head;//if first student is to be deleted
            head = head->next;
            free(z);
            flag = 1;
        }
        else{
            temp = head;
            while(temp != NULL){
                if(temp->rollnumber == rollnumber && temp->batch == batch){//else any other student to be deleted
                    ptemp->next = temp->next;
                    free(temp);
                    flag = 1;
                    break;
                }
                else{
                    ptemp = temp;
                    temp = temp->next;
                }        
            }
        }    
        if(flag == 1){
            printf(" Roll number \"%d\" deleted successfully\n",rollnumber);//to know whether the given student is deleted or //not
        }
        else{
            printf("\"%d\" No such rollnumber exists\n",rollnumber);
        }
        return head;
   }
}


struct student * del_one_batch(struct student * head,int batch){
    if(head == NULL){//to know file is empty or not
        printf("NO STUDENT EXISTS\n");
        return head;
    }
    else{
        struct student * temp;
        temp = head;
        while(temp != NULL){
            if(temp -> batch == batch){
                head = del_one_student(head,temp->batch,temp->rollnumber);//it uses del_one_student
            }
            temp = temp->next;
        }
        return head;
    }
}

//to be ignored
void display_students(struct student * head){
    struct student * temp = head;
    while(temp != NULL){
        printf("%s\n",temp->name);
        temp = temp->next;
    }

}

//the code which will interact with user and call above functions
void interact(void){
    struct student *students;//head of linked list it will be initialised on line 123 where filetolist is called
    that:
    printf("HELLO SIR.\n1. DELETE ONE STUDENT\n2. DELETE ONE WHOLE BATCH.\n\nPress 0 to go back\n\n");
    int which_function;
    scanf("%d",&which_function);
    if(which_function == 1){
        printf("PLEASE ENTER THE BATCH NUMBER OF STUDENT TO BE DELETED(1, 2, 3 or 4 only) : \n");
        int batch,rollnumber;
        scanf("%d",&batch);
        if(batch>4 || batch<1)
        {
            printf("\nNo such batch exists!!\n");
            goto that;
        }
        printf("PLEASE ENTER THE ROLLNUMBER OF STUDENT TO BE DELETED\n");
        scanf("%d",&rollnumber);
        filetolist(&students);//make linked list from database.txt
        students = del_one_student(students,batch,rollnumber);
        listtofile(students);//again make text file after doing some edits
    }
    else if(which_function == 2){
        printf("PLEASE ENTER THE BATCH NUMBER TO BE DELETED\n");
        int batch_number;
        scanf("%d",&batch_number);
        if(batch_number>4 || batch_number<1)
        {
            printf("\nNo such batch exists!!\n");
            goto that;
        }
        filetolist(&students);//make linked list from database.txt
        students = del_one_batch(students,batch_number);
        listtofile(students); //again make text file after doing some edits 
    }
    else if(which_function != 0 && which_function != 1 && which_function != 2)
    {   
        printf("\nPlease! Choose options: 0, 1 or 2 only.\n");
        interact();//if user by mistake puts wrong input then call it again
    }
}
//this is main menu to be displayed after login
void main_menu(void){
    printf("1. ENTER NEW STUDENT DETAILS\n");
    printf("2. DELETE THE STUDENT DETAILS\n");
    printf("3. SEARCH SOME DETAILS\n");
    printf("4. STUDENT ENTRY/EXIT DETAILS\n");
    printf("5. UPDATE INFORMATION OF STUDENTS\n");
    printf("6. DISPLAY INFORMATION OF STUDENTS\n");
    printf("7. INFORMATION ABOUT HOSTEL\n");
    printf("0. LOG OUT\n"); 
}
