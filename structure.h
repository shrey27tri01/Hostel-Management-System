#pragma once
#include <stdio.h>
#include <stdlib.h>


struct student
{	
	char *name;
	char *DOB;
	int rollnumber;
	int batch;
	int status;
	char gender;
	int roomnumber;
	char *contact;
	char *email;
	struct student *next;
};