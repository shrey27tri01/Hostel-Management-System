#include "headers/add.h"

struct details{
	char name[100];
    char Date_of_Birth[100];
	int rollnumber;
	int year;
	int status;
	char gender;
	int roomnumber;
	char Contact[100];
	char Email[1000];
	struct details *next;
};
void sort(int room[],int n)
{
	{ 
    int i, key, j; 
    for (i = 1; i < n; i++) { 
        key = room[i]; 
        j = i - 1; 
        while (j >= 0 && room[j] > key) { 
            room[j + 1] = room[j]; 
            j = j - 1; 
        } 
        room[j + 1] = key; 
    } 
} 
}
void add()
{
	//Create a structure which has details of student
	
	//Create 3 file pointers fp1 will point to database fp2 will point to the last room number fp3 will point to the roll number
	FILE *fp;
	fp=fopen("database.txt","a");
	typedef struct details node;
	//Create three nodes and point them to NULL
	node *temp=NULL;
	struct student *students,*temp2=NULL;
	//Create an array to store all the room numbers
	int rollnumber=0,room[40],i,flag=0,roomnumber=0,j,choice;
	there:
	printf("\nEnter 1 to Enter New Student Details and 0 to return to Main Menu : ");
	scanf("%d",&choice);
	if(choice==1)
	{
			for(i=0;i<40;i++)
			{
				room[i]=0;
			}
			//Call the filetolist function to get the rollnumber and roomnumber
			filetolist(&students);
			//Initialize temp2 to students
			temp2=students;
			//Allocate memory for temp node
			temp=(node*)malloc(sizeof(node));


			printf("Enter the details of the students\n\n");
			printf("Enter the Name of the student:");
			scanf("\n%[^\n]s",temp->name);


			printf("\nEnter your Date of Birth(DD/MM/YYYY) : ");
			fscanf(stdin,"%s",temp->Date_of_Birth);


			printf("\nEnter the Gender of the student");
			printf("\nEnter M for Male and F for Female:");


			fscanf(stdin,"\n%c",&(temp->gender));
			here:
			printf("\nEnter batch(1,2,3,4) : ");
			fscanf(stdin,"%d",&(temp->year));
			if(temp->year!=1 && temp->year!=2 && temp->year!=3 && temp->year!=4)
			{
				printf("Enter batch as 1, 2, 3 or 4 only.");
				goto here;
			}
			//Open the Data base we created in append mode
			temp->status=0;
			printf("\n");
			//Run a while loop to get the last roll number of the entered batch/year
			while(temp2!=NULL)
				{
					if(temp2->batch==temp->year)
					{
						if(temp2->rollnumber>=rollnumber)
						{
							rollnumber=temp2->rollnumber;
						}
					}
					temp2=temp2->next;
				}
			//If the gender is male then go into this if loop
			if(temp->gender=='M')
			{
				//Initialize the temp2 to students again and run a while loop to get the last room number of the batch
				temp2=students;
				j=0;
				while(temp2!=NULL)
				{
					if(temp2->batch==temp->year && temp2->gender==temp->gender)
					{
						room[j]=temp2->roomnumber;
						j++;
						if(temp2->roomnumber>=roomnumber)
						{
							roomnumber=temp2->roomnumber;
						}
					}
					temp2=temp2->next;
				}

			}
			//If the gender is female then go into this if loop
			if(temp->gender=='F')
			{
				//Initialize the temp2 to students again and run a while loop to get the last room number of the batch
				j=0;
				temp2=students;
				while(temp2!=NULL)
				{
					if(temp2->batch==temp->year && temp2->gender==temp->gender)
					{
						room[j]=temp2->roomnumber;
						j++;
						if(temp2->roomnumber>=roomnumber)
						{
							roomnumber=temp2->roomnumber;
						}
					}
					temp2=temp2->next;
				}
			}

			sort(room,j);
			if(j!=40)
			{
				if(roomnumber!=0 && room[0]==(temp->year)*100+1)
				{
					for(int k=0;k<j-1;k++)
					{
						if(room[k]+1!=room[k+1])
						{
							flag=1;
							temp->roomnumber=room[k]+1;
							break;
						}
					}
					if(flag==0)
					{
						temp->roomnumber=room[j-1]+1;
					}
				}
				if(roomnumber!=0 && room[0]!=(temp->year)*100+1)
				{
					temp->roomnumber=(temp->year)*100+1;
				}
				if(roomnumber==0)
				{
					temp->roomnumber = (temp->year)*100+1;
				}
				printf("\nEnter the Contact:");
				scanf("%s",temp->Contact);
				printf("\nEnter the Email:");
				scanf("%s",temp->Email);
				if(temp->gender == 'M')
					printf("\n\"%s\" is alloted rollnumber as %d, and roomnumber as %d in Bhaskara Boys Hostel.\n", temp->name, rollnumber+1, temp->roomnumber);
				else
					printf("\n\"%s\" is alloted rollnumber as %d, and roomnumber as %d in Lilavati Girls Hostel.\n", temp->name, rollnumber+1, temp->roomnumber);
				//Write all the details of the student entered above into the file 
				fprintf(fp,"%s| %s | %d | %d | %d | %c | %d | %s | %s |\n",temp->name,temp->Date_of_Birth,temp->year,rollnumber+1,temp->status,temp->gender,temp->roomnumber,temp->Contact,temp->Email);
			}
			else{
				if(temp->gender == 'M')
					printf("Boys Hostel Bhaskara is FULL!!!\n");
				else
					printf("Girls Hostel Lilavati is FULL!!!\n");			
			}

			fclose(fp);
	}
	else if(choice!=0 && choice!=1)
	{
		printf("\nPlease!! Enter 1 or 0 only\n");
		goto there;
	}
}
