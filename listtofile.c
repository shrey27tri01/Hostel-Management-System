#include "headers/listtofile.h"

void listtofile(struct student *students)
{
	FILE *f;
	f = fopen("database.txt", "w");//open this in w mode so it overwrites the previous data
	struct student *temp = students;//the head of linked list 
	while(temp!=NULL)
	{
			fprintf(f, "%s| %s | %d | %d | %d | %c | %d | %s | %s |\n", temp->name, temp->DOB, temp->batch, temp->rollnumber, temp->status, temp->gender, temp->roomnumber, temp->contact, temp->email);
			temp = temp->next;
	}
	fclose(f);
}
