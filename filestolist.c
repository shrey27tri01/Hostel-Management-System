//Function to Fetch Data From The Database file and make a linked list out of it in the same order

#include "headers/filetolist.h"

void filetolist(struct student ** students)
{
    FILE* fp;	//Declaring a File Pointer
    fp = fopen("database.txt","r");	//Opening the Database file through our File pointer in "Read Mode"

	char* str1 = (char*)malloc(100*sizeof(char));		//Dynamically allocating memory to store name of the student
	char* contact = (char*)malloc(15*sizeof(char));		//Dynamically allocating memory to store Contact no. of the student
	char* email = (char*)malloc(100*sizeof(char));		//Dynamically allocating memory to store Email of the student
	char* DOB = (char*)malloc(15*sizeof(char));		//Dynamically allocating memory to store Date of birth of the student
	int rollnumber,status, roomnumber, batch; 		
	char c;	//stores gender of the Student
	
	int i=1;
	
	struct student *temp;

	int k=fscanf(fp,"%[^|]s",str1);	 
	int j=fscanf(fp,"| %s | %d | %d | %d | %c | %d | %s | %s |\n", DOB, &batch, &rollnumber,&status, &c, &roomnumber, contact, email);	
    if(j==EOF || k==EOF)	//Condition to check if Database File is empty
    {
    	*students = NULL;
    	i=2;
    }
    while(k!=EOF || j!=EOF)	//Loop to append the Data from Database file to the linked list
    {
		if(k!=EOF)
		{
			struct student *temp1=(struct student*)malloc(sizeof(struct student));
			temp1->name = str1;
		   	temp1->gender = c;
           	temp1->batch = batch;
			temp1->rollnumber = rollnumber;
			temp1->status = status;
			temp1->contact = contact;
			temp1->email = email;
			temp1->DOB = DOB;
			temp1->roomnumber = roomnumber;	
			temp1->next=NULL;
			
			if(i==1)
			{
				*students=temp1;
				temp=*students;
			}
			else
			{
				temp->next=temp1;
				temp=temp->next;
			}
			str1 = (char*)malloc(100*sizeof(char));
			contact = (char*)malloc(15*sizeof(char));
			email = (char*)malloc(100*sizeof(char));
			DOB = (char*)malloc(15*sizeof(char));
			
			k=fscanf(fp,"%[^|]s",str1);
        	j=fscanf(fp,"| %s | %d | %d | %d | %c | %d | %s | %s |\n", DOB, &batch, &rollnumber,&status, &c, &roomnumber, contact, email);		
			i++;	
		}		
       }
       	free(DOB);
		free(contact);
		free(email);
		free(str1);
		fclose(fp);
}
