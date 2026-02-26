#include <stdio.h>
#include <stdlib.h>

void readDot(void)
	{
	FILE* f;
	fptr = fopen("graph.dot","r");
	if(fptr == NULL)
		{
			printf("File not opened, please check if your graph.dot file exists in this 					directory");
		}
	}

