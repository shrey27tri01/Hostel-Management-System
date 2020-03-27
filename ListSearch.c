#include "headers/ListSearch.h"

char *mystrlwr(char *string)	//Function to Handle the case of "Case Sensitivity" while searching
{
  unsigned char *c = (unsigned char *)string;

  while (*c) 
  {
     *c = tolower((unsigned char)*c);
      c++;
  }

  return string;
}
//Function To Search By Name ("It gives the Result Based on Keywords Also")
void searchByName(char*string)
{
	int count=0;
	struct student *temp=head;
	char *s = malloc(100*sizeof(char));
	while(temp!=NULL)
	{
		strcpy(s,temp->name);
		if(strncmp(mystrlwr(s),mystrlwr(string),strlen(string))==0)
        {
			count = 1;                        
			printf("NAME : %s\n",temp->name);
            printf("DATE OF BIRTH : %s\n",temp->DOB);
			printf("ROLL NUMBER : %d\n",temp->rollnumber);
            printf("BATCH : %d\n",temp->batch);
			printf("GENDER : %c\n",temp->gender);
			if(temp->gender == 'M')
			{
				printf("HOSTEL : Bhaskara\n");
			}
			else
			{
				printf("HOSTEL : Lilavati\n");
			}
			printf("ROOM NUMBER : %d\n",temp->roomnumber);
			printf("CONTACT : %s\n",temp->contact);
			printf("EMAIL : %s\n",temp->email);
            printf("\n");
        }
		temp=temp->next;
	}
	if(count==0)
		printf("No Records Found\n");
	free(s);
}

//Function To search by Batch

void searchByBatch(int n)
{
	struct student *temp=head;
    int count = 0;
   	while(temp!=0)
    {
        if(temp->batch==n)
        {
         	count = 1;
            printf("NAME : %s\n",temp->name);
            printf("DATE OF BIRTH : %s\n",temp->DOB);
			printf("ROLL NUMBER : %d\n",temp->rollnumber);
            printf("BATCH : %d\n",temp->batch);
            printf("GENDER : %c\n",temp->gender);
            if(temp->gender == 'M')
			{
				printf("HOSTEL : Bhaskara\n");
			}
			else
			{
				printf("HOSTEL : Lilavati\n");
			}
            printf("ROOM NUMBER : %d\n",temp->roomnumber);
            printf("CONTACT : %s\n",temp->contact);
            printf("EMAIL : %s\n",temp->email);
            printf("\n");
        }
        temp=temp->next;
    }   
    if(count==0)
		printf("No Records Found\n"); 
}

// Function To Search by Room
void searchByRoom(int n)
{
    struct student *temp=head;
    int count = 0;
    while(temp!=0)
    {
    	if(temp->roomnumber==n)
        {
            count = 1;
            printf("NAME : %s\n",temp->name);
            printf("DATE OF BIRTH : %s\n",temp->DOB);
            printf("BATCH : %d\n",temp->batch);
			printf("ROLL NUMBER : %d\n",temp->rollnumber);  
            printf("GENDER : %c\n",temp->gender);
            if(temp->gender == 'M')
			{
				printf("HOSTEL : Bhaskara\n");
			}
			else
			{			
				printf("HOSTEL : Lilavati\n");
			}
            printf("ROOM NUMBER : %d\n",temp->roomnumber);
            printf("CONTACT : %s\n",temp->contact);
            printf("EMAIL : %s\n",temp->email);
            printf("\n");
        }
        temp=temp->next;
    }
    if(count==0)
		printf("No Records Found\n");
}

// Common Function That asks User the Kind of search he wants and Call the Search Function accordingly
void search()
{
	int choice;
	filetolist(&head);
	if(head!=NULL)
	{
		printf("Search By\n\n1.Name\n2.Batch\n3.Room Number\n\nPress 0 to go back\n\n");

		printf("Enter code corresponding to your choice : ");
		
		scanf("%d",&choice);

		switch(choice){

			case 1:	printf("Enter the Name or Keyword: ");
				char name[100];
				scanf("\n%[^\n]s",name);
				searchByName(name);
				break;

			case 2: printf("Enter Batch(1,2,3,4) : ");
				int batch;
				scanf("%d",&batch);
				searchByBatch(batch);
				break;

			case 3: printf("Enter the Room Number : ");
				int room;
				scanf("%d",&room);
				searchByRoom(room);
				break;
			case 0: 
				break;

			default: printf("Invalid Response!\n");
					search();
					break;

		}
	}
	else
	{
		printf("\n\nNO RECORDS FOUND!!\n\n");
	}
}
