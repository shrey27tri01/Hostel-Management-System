#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "structure.h"
#include "filetolist.h"
#include "listtofile.h"


void security_check(void);
struct student * del_one_student(struct student * head,int batch,int rollnumber);
struct student * del_one_batch(struct student * head,int batch);
void main_menu(void);
void interact(void);
