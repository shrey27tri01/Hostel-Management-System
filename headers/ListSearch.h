#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include"structure.h"
#include "filetolist.h"
char *mystrlwr(char *string);
void search();
void searchByName();
void searchByRoom();
void searchByBatch();

struct student* head;
