#include "headers/display.h"

void display_all()
{
	struct student* students, *temp;
	char *hostel;
	hostel = malloc(10*sizeof(char)); // Memory Allocation
	filetolist(&students); // Passing Address of Head of Linked List (students)
	temp = students;
	while(temp!=NULL)
	{
		if(temp->gender == 'M') // For Male students
		{
			hostel = "Bhaskara";
		}
		else // For Female students
		{
			hostel = "Lilavati";
		}
		printf("%-25s %-12s %-3d %-3d %-3c %s %-3d %-12s %-20s\n", temp->name, temp->DOB, temp->batch, temp->rollnumber, temp->gender, hostel, temp->roomnumber, temp->contact, temp->email);
		temp = temp->next;
	}
}

void display_boys() // Function to display boys
{
        struct student* students, *temp;
        filetolist(&students);
        temp = students;
        while(temp!=NULL)
        {
                if(temp->gender == 'M')
		{
		printf("%-25s %-12s %-3d %-3d %-3c Bhaskara %-3d %-12s %-20s\n", temp->name, temp->DOB, temp->batch, temp->rollnumber, temp->gender, temp->roomnumber, temp->contact, temp->email);
		}
		temp = temp->next;
        }
}

void display_girls() // Function to display girls
{
        struct student* students, *temp;
        filetolist(&students);
        temp = students;
        while(temp!=NULL)
        {
                if(temp->gender == 'F')
                {
                printf("%-25s %-12s %-3d %-3d %-3c Lilavati %-3d %-12s %-20s\n", temp->name, temp->DOB, temp->batch, temp->rollnumber, temp->gender, temp->roomnumber, temp->contact, temp->email);
                }
                temp = temp->next;
        }
}

void display_batch() // Function to display students of any particular batch
{
	struct student* students, *temp;
	filetolist(&students);
	temp = students;
	printf("Enter the batch no.(1,2,3 or 4) : ");
	int choice;
	char *hostel;
	hostel = malloc(10*sizeof(char));
	scanf("%d", &choice);
	printf("\nPress 1 to display all students of batch %d : ", choice);
	printf("\nPress 2 to display all boys of batch %d : ", choice);
    printf("\nPress 3 to display all girls of batch %d : ", choice);
	int subchoice;
	scanf("%d", &subchoice);
	switch(subchoice){
		case 1: while(temp!=NULL) // To display all students of a batch
			{
				if(temp->batch == choice)
				{
					if(temp->gender == 'M')
					{
						hostel = "Bhaskara";
					}
					else
					{
						hostel = "Lilavati";
					}
					printf("%-25s %-12s %-3d %-3d %-3c %s %-3d %-12s %-20s\n", temp->name, temp->DOB, temp->batch, temp->rollnumber, temp->gender, hostel, temp->roomnumber, temp->contact, temp->email);
				}
				temp=temp->next;
			}
			break;
		case 2: while(temp!=NULL) // To display all boys a batch
                        {
				if(temp->batch == choice && temp->gender == 'M')
                                {
                                        printf("%-25s %-12s %-3d %-3d %-3c Bhaskara %-3d %-12s %-20s\n", temp->name, temp->DOB, temp->batch, temp->rollnumber, temp->gender, temp->roomnumber, temp->contact, temp->email);
                                }
                                temp=temp->next;
                        }
                        break;
		case 3: while(temp!=NULL) // To display all girls of a batch
                        {
                                if(temp->batch == choice && temp->gender == 'F') 
                                {
                                        printf("%-25s %-12s %-3d %-3d %-3c Lilavati %-3d %-12s %-20s\n", temp->name, temp->DOB, temp->batch, temp->rollnumber, temp->gender, temp->roomnumber, temp->contact, temp->email);
                                }
                                temp=temp->next;
                        }
                        break;
	}
	
}

void display() // Display Function to call other functions of Display
{
	printf("To display all students, press 1\nTo display all boys, press 2\nTo display all girls, press 3\nTo display students batchwise, press 4 \n\nPress 0 to go to main menu : ");
	int choice;
	scanf("%d", &choice);
	switch(choice){
		case 1: display_all();
			break;
		case 2: display_boys();
			break;
		case 3: display_girls();
			break;
		case 4: display_batch();
			break;
		case 0: break;
		default: printf("Invalid Input\n");
	}
}
