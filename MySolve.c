
/*
MySolve
*/

#ifndef _MYSOLVE

#define _MYSOLVE


#include "MyData.h"
#include "MyCalCount.c"
#include "MyCheck.c"
#include "MyIO.c"

int _solve_(int h, int w)
{
	if( h>MAP_H )
	{
		if( Check_White_All()==1 )
			if( Check_Cnt()==1 )  
				return 1;
		return 0;
	}
	if( w>MAP_W )return _solve_(h+1, 1);
	
	if( COUNTofH(h, w)>1 || COUNTofW(h, w)>1 )
	{
		if( Check_Black(h, w)==1 )
		{
			Line[h][w]=1; // 是否需要先判断 Line[h][w]==0 
			cntofBlack++;
			COUNTofH(h, w)--; // 是否之前需要判断非0 
			COUNTofW(h, w)--;
			
			if( Check_White_All()==1 )
				if( _solve_(h, w+1)==1 )
					return 1;
			
			Line[h][w]=0;
			cntofBlack--;
			COUNTofH(h, w)++;
			COUNTofW(h, w)++;
		}
	}
	
	return _solve_(h, w+1);
}

int Solve_Hitori()
{
	//CalCnt();
	
	InitLine();
	return _solve_(1, 1);
}


#endif

