#include "headers/update.h"

void update()
{
   	struct student* head;				//head is an object of the structure student
   	filetolist(&head);
   	if(head == NULL){
   		printf("\nNo records found\n\nNo data to update!!\n");
   		// return head;
   	}
   	else{
	int flag = 0, flag2 = 1;
    int response;
	struct student *current  = malloc(sizeof(struct student)*1);	//allocate memory to the object current of structure student
   	int roll_no;
	int take_batch;
	int choice;
	int *rooms = calloc(320,(sizeof(int)));
	here:
	printf("1.UPADTE STUDENT INFORMATION\n0.BACK TO MAIN MENU\n");
	scanf("%d",&choice);
	if(choice == 1)
	{
		up:
		printf("Enter the batch number(1, 2, 3 or 4) of the student whose information you want to update : "); 			    scanf("%d",&take_batch);
		if(take_batch!=1 && take_batch!=2 && take_batch!=3 && take_batch!=4)
		{
			printf("\nInvalid batch number entered!\n");
			goto up;
		}
    				
		current = head;						//head is assigned to the current node, current
		printf("\nEnter roll number of the student of batch %d, whose information you want to update : ", take_batch);
		scanf("%d", &roll_no);
		while(current != NULL)					//to check with all the nodes present in the list
		{
			if(current->rollnumber == roll_no && current->batch == take_batch)	//if the roll number and batch match with an existing information in the list
			{
				flag = 1;
				printf("Old details are: \n");
				printf(" Name : %-25s\n DOB : %-12s\n Batch : %-3d\n Roll Number : %-3d\n Gender : %-3c\n Room Number : %-3d\n Contact : %-12s\n Email : %-20s\n", current->name, current->DOB, current->batch, current->rollnumber, current->gender, current->roomnumber, current->contact, current->email);
					break;
			}
			current = current -> next;		//To go to the next node	
    		}
    		if(flag == 0)
    		{
    			printf("\n\nThis roll number does not exist!!\n");
    		}
    		else
    		{
    			there:
    			printf("1. Enter 1 to update name\n");
    			printf("2. Enter 2 to update Date Of Birth\n");
    			printf("3. Enter 3 to update Room Number\n");
    			printf("4. Enter 4 to update contact number\n");
    			printf("5. Enter 5 to update email id\n");
    			printf("6. Enter 6 to go back to main menu\n");
    			scanf("%d",&response);

				char *name;
				char *DOB;
    			// int batch;
				int roomnumber;
				char *contact;
				char *email;
				switch(response)
				{
   			     	case 1:							//to change the name
				    		name = malloc(sizeof(char)*100);
				    		printf("Enter name of student : \n");
   			         		scanf("\n%[^\n]s",name);
				    		current->name = name;
				    		// free(name);
   			         		break;
   			     	case 2:							//to change DOB
				    		DOB = malloc(sizeof(char)*100);
   			         		printf("Enter Date of Birth of the student : \n");
   			         		scanf("%s",DOB);
				    		current->DOB = DOB;
				    		// free(DOB);
   			         		break;
   			    
   			     	case 3:							//to change roomnumber
   			         		printf("Enter roomnumber : \n");
							struct student *temp = head;
							int i = 0,count = 0,helper = 0;
							while(temp != NULL){
								if(temp->gender == current->gender)
								{
									rooms[i] = temp->roomnumber;
									i++;
									count++;
								}
								temp = temp->next;
							}
   			         		scanf("%d",&roomnumber);
   			         		if(roomnumber >take_batch * 100  && roomnumber < take_batch * 100 + 41){
							for(i = 0;i<count;i++){
								if(roomnumber == rooms[i]){
									printf("THIS ROOM IS TAKEN\n");
									flag2 = 0;
									helper = 1;
									break;
								}
							}
							if(helper == 0){
				    			current->roomnumber = roomnumber;
							}
							break;
						}
						else{
							printf("BATCH %d STUDENTS SHOULD BE ALLOTTED IN ROOMS BETWEEN %d01 AND %d40\n", take_batch, take_batch, take_batch);
							goto here;
						}
   			     	case 4:							//to change contact
				    		contact = malloc(sizeof(char)*100);
   			         		printf("Enter contact number: \n");
   			         		scanf("%s",contact);
				    		current->contact = contact;
				    		// free(contact);
   			         		break;
   			     	case 5:							//to change email
				    		email = malloc(sizeof(char)*100);
   			         		printf("Enter email : \n");
   			         		scanf("%s",email);
				    		current->email = email;
				    		// free(email);
   			         		break;
					case 6:
							goto here;
							break;
   			     	default:
   			     			printf("Please enter from the given options\n");
				    		goto there;
    			}
				listtofile(head);
				if(flag2 == 1)
					printf("\nStudent information updated successfully!!\n");
				else
					printf("\nStudent information not updated!!\n\n");
			}
		}
		else if(choice != 1 && choice != 0)
		{
			printf("Please!! select from given options(1 or 0,only)!!\n");
			goto here;
		}
		free(current);
	}
}
