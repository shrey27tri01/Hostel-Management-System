//Function to Sort the Data Of Students in Alphabetical Order

#include "headers/ListSort.h"


void Adjswap(int pos1, int pos2)	//Function to swap the Adjacent nodes in linked list (Used further when sorting the linked list) 
{
	int i;
	struct student *temp3=NULL;	
	struct student *temp1=head;
	struct student *temp2=head;

	if(pos1==1)	//Condition When first two nodes need to be swapped
	{		
		head=temp1->next;
		temp3=head->next;
		head->next=temp1;
		temp1->next=temp3;	
	}
	else		//Condition When other than first two nodes need to be swapped
	{

		temp3=head;
		for(i=0;i<pos2-3;i++)	//traversing the linked list to reach the position such that the required nodes can be swapped
		{
			temp1=temp1->next;
			temp2=temp2->next;
			temp3=temp3->next;
		}
		temp2=temp2->next;
		temp3=temp2->next;
		
		temp2->next=temp3->next;
		temp3->next=temp1->next;
		temp1->next=temp3;	
	}
}

int nodesTotal()	//Function to count total number of nodes
{
	struct student *temp=head;
	int i=1;
	while(temp->next!=0)	//traversing the linked list
	{
		temp=temp->next;	
		i++;	//counter to count number of nodes
	}
	return i;	//returning the number of nodes
}	
void Fullsort()		//Function to sort the list using "Bubble Sort Algorithm"
{
	filetolist(&head);	//Calling "filetolist" function to fetch all the data in file and make a linked list out of it
	if(head != NULL)
	{
		struct student *temp=head;	
		int t;
		int n=nodesTotal();
		int i,j;
		for(i=0;i<n-1;i++)
		{
			temp=head;
			for(j=1;j<n;j++)	//Loop to send the lexographically largest name to last
			{
				if(strcmp(temp->name,(temp->next)->name)>0)	//condition to compare two names according to lexographical order
				{
					temp=temp->next;	//traversing the linked list to sort the data
					Adjswap(j,j+1);		//Swapping if first name encountered is greater than the next name

				}
				temp=temp->next;
			}
		}

		listtofile(head);	//Calling the "listtofile" function to write all data from sorted linked list to the database file in 					  alphabetical order
	}
}
