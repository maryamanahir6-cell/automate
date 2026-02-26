#include <stdio.h>
#include <stdlib.h>
#define MAX 20
void readDot(int A[20][20])
	{
	FILE* f;
	fptr = fopen("graph.dot","r");
	if(fptr == NULL)
		{
			printf("File not opened, please check if your graph.dot file exists in this directory");
		}
	fscanf(file, "%s");
	while( fscanf(f," %c -> %c [label=\"%d\"]",&src,&dest,&val ) == 3)
			{
				A[src][dest] = 1;
			}
	}
