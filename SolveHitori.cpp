
/*
SolveHitori
*/


#include <stdio.h>
#include <stdlib.h>

#include "MyData.h"
#include "MyCalCount.c"
#include "MyCheck.c"
#include "MyIO.c"
#include "MySolve.c"


int main()
{
	/*
	PrintLine();
	
	int th, tw;
	scanf("%d %d", &th, &tw);
	flag[th][tw]=1;
	printf("%d", CalCount(th, tw));
	// test Functions : printLine, CalCount
	*/
	
	/*
	InitMap();
	PrintMap();
	ScanMap();
	PrintMap();
	// test Functions : InitMap, PrintMap, ScanMap
	*/
	
	
	printf("Question : \n"); 
	ScanMap();
	printf("Answer : \n"); 
	Solve_Hitori();
	
	system("pause");
	return 0;
}


