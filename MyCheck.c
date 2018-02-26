
/*
MyCheck
*/


#ifndef _MYCHECK

#define _MYCHECK


#include "MyData.h"

int Check_White_All() // ��� �׸����Ƿ�ȫ������ 
{
	int h, w, cntW;
	for(h=1; h<=MAP_H; h++)
		for(w=1; w<=MAP_W; w++) 
			if( Line[h][w]==0 )
			{
				cntW=CalCount(h, w);
				if( cntW==(MAP_H*MAP_W-cntofBlack) )return 1;
				else return 0;
			}
	
	if( h>MAP_H && w>MAP_W )cntW=0; // 0:�ް׸�Ҳ���� / -1:�ް׸񲻿���  
	if( cntW==(MAP_H*MAP_W-cntofBlack) )return 1;
	else return 0;
}

int Check_Black(int h, int w) // ���ĳ�������Ƿ��кڸ��� (�ޣ�1 / �У�0) 
{
	int dir;
	for(dir=1; dir<=4; dir++)
		if( Line[Dh][Dw]==1 )
			return 0;
	return 1;
}

int Check_Cnt() // �����������Ƿ�û���ظ��� 
{ 
	int h, w;
	for(h=1; h<=MAP_H; h++)
		for(w=1; w<=MAP_W; w++)
			if( COUNTofH(h, w)>1 || COUNTofW(h, w)>1 )
				return 0;
	return 1;
}


#endif

