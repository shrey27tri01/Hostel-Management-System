#include "headers/inout.h"
// this function deals with studrnt entry/exit details
// it can also display the list of students who are inside the hostel and who are out 
// this uses  in linked list and listtofile and filetolist 
// just call status in main function and include inout.h
void status()
{
	struct student *students, *temp, *temp1;
	filetolist(&students);
	temp = students;
	int batch, rollnumber;
	here:
	printf("Press : \n\t1 for going out, \n\t2 for going in, \n\t3 for displaying students who are out, \n\t4 for displaying students who are in. \n\tPress 0 to go to main menu : \n");
	int choice;
	int helper = 0;
	scanf("%d", &choice);
	if(choice != 0 && choice != 1 && choice != 2 && choice != 3 && choice != 4)
	{
		printf("\nPlease! Choose 1, 2, 3, 4 or 0 only.\n");
		goto here;//if the user puts some wrong input 
	}
	while(choice==1 || choice==2)
	{
		printf("Enter batch(1, 2, 3 or 4 only) : ");
		scanf("%d", &batch);
		printf("Enter rollnumber : ");
		scanf("%d", &rollnumber);
		temp = students;//students is head of linked list
		if(choice == 1)
		{
			while(temp!=NULL)
			{
				if(temp->batch == batch && temp->rollnumber == rollnumber)
				{
					helper = 1;
					if(temp->status==0)
					{
						temp->status = 1;
						printf("%s is out.\n", temp->name);
					}
					else
					{	
						printf("%s is already out.\n", temp->name);
					}
				}
				temp = temp->next;
			}

		}
		else if(choice == 2)
		{
			while(temp!=NULL)
			{
				if(temp->batch == batch && temp->rollnumber == rollnumber)
				{
					helper = 1;
					if(temp->status==1)
					{
						temp->status = 0;
						printf("%s is in.\n", temp->name);
					}
					else
					{	
						printf("%s is already in.\n", temp->name);
					}
				}	
				temp = temp->next;
			}
		}
		if(helper==0)
		{
			printf("No record found!!\n");
		}
		helper = 0;
		printf("Press 0 for exit, 1 for going out, 2 for going in : ");
		scanf("%d", &choice);
	}
	if(choice == 3 || choice == 4)
	{
		temp = students;
		if(choice == 3)
		{
			while(temp!=NULL)
			{
				if(temp->status == 1)
				{
					printf("%-25s %-12s %-3d %-3d %-3c %-3d %-12s %-20s\n", temp->name, temp->DOB, temp->batch, temp->rollnumber, temp->gender, temp->roomnumber, temp->contact, temp->email);
				}
				temp = temp->next;
			}
		}
		else if(choice == 4)
		{
			while(temp!=NULL)
			{
				if(temp->status == 0)
				{
					printf("%-25s %-12s %-3d %-3d %-3c %-3d %-12s %-20s\n", temp->name, temp->DOB, temp->batch, temp->rollnumber, temp->gender, temp->roomnumber, temp->contact, temp->email);
				}
				temp = temp->next;
			}
		}

	}
	listtofile(students);//make text file from updated linked list 
}
