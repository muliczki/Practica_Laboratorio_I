#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Post.h"
#include "User.h"
#include "Feed.h"



int parser_PostFromText(FILE* pFile , LinkedList* pArrayListPost);

int parser_UserFromText(FILE* pFile , LinkedList* pArrayListUser);

/*
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);
*/
