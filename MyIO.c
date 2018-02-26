
/*
MyIO
*/


#ifndef _MYIO

#define _MYIO


#include <stdio.h>
#include "MyData.h"

void InitMap()
{
	int h, w, n;
	
	// 内 
	for(h=1; h<=MAP_H; h++)
		for(w=1; w<=MAP_W; w++)
			Map[h][w]=0;
	
	// 边 ( 竖, 横 ) 
	for(h=1; h<=MAP_H; h++)
	{
		Map[h][0]=-4;
	 	Map[h][MAP_W+1]=-4;
	} 
	for(w=1; w<=MAP_W; w++)
	{
		Map[0][w]=-5;
	 	Map[MAP_H+1][w]=-5;
	} 
	
	// 角 
	n=-9;
	for(h=0; h<=MAP_H+1; h+=MAP_H+1)
		for(w=0; w<=MAP_W+1; w+=MAP_W+1)
			Map[h][w]= (n++);
	
}

void InitLine()
{
	int h, w, n;
	
	// 内 
	for(h=1; h<=MAP_H; h++)
		for(w=1; w<=MAP_W; w++)
			Line[h][w]=0;
	cntofBlack=0;
	
	// 边 ( 竖, 横 ) 
	for(h=1; h<=MAP_H; h++)
	{
		Line[h][0]=-4;
	 	Line[h][MAP_W+1]=-4;
	} 
	for(w=1; w<=MAP_W; w++)
	{
		Line[0][w]=-5;
	 	Line[MAP_H+1][w]=-5;
	} 
	
	// 角 
	n=-9;
	for(h=0; h<=MAP_H+1; h+=MAP_H+1)
		for(w=0; w<=MAP_W+1; w+=MAP_W+1)
			Line[h][w]=	(n++);
}

// ？待：合并 


void CalCnt()
{
	int h, w, t;
	
	for(h=1; h<=MAP_H; h++)
		for(w=1; w<=MAP_W; w++)
		{
			cntofH[h][w]=0;
			cntofW[h][w]=0;
		}
	
	for(h=1; h<=MAP_H; h++)
		for(w=1; w<=MAP_W; w++)
		{
			t=Map[h][w];
			cntofH[h][t]++;
			cntofW[t][w]++;
		}
	
	// 待：判断 t 合法之后再执行 
}

void ScanMap()
{
	InitMap();
	int h, w;
	for(h=1; h<=MAP_H; h++)
		for(w=1; w<=MAP_W; w++)
			scanf("%d", &Map[h][w]);
	CalCnt();
}


void PrintMap()
{
	int h, w;
	for(h=0; h<=MAP_H+1; h++)
	{
		for(w=0; w<=MAP_W+1; w++)
		{
			     if( Map[h][w]==-9 )printf("┏");
			else if( Map[h][w]==-8 )printf("┓");
			else if( Map[h][w]==-7 )printf("┗");
			else if( Map[h][w]==-6 )printf("┛");
			else if( Map[h][w]==-5 )printf("━");
			else if( Map[h][w]==-4 )printf("┃");
			else printf("%-2d", Map[h][w]);
		}
		printf("\n");
	}
}

void PrintLine()
{
	int h, w;
	for(h=0; h<=MAP_H+1; h++)
	{
		for(w=0; w<=MAP_W+1; w++)
		{
				 if( Line[h][w]== 1 )printf("■");
			else if( Line[h][w]==-9 )printf("┏");
			else if( Line[h][w]==-8 )printf("┓");
			else if( Line[h][w]==-7 )printf("┗");
			else if( Line[h][w]==-6 )printf("┛");
			else if( Line[h][w]==-5 )printf("━");
			else if( Line[h][w]==-4 )printf("┃");
			else printf("%-2d", Map[h][w]);
		}
		printf("\n");
	}
}

#endif

