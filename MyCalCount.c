
/*
MyCalCount
*/


#ifndef _MYCALCOUNT

#define _MYCALCOUNT


#include "MyData.h"

int flag[1+MAP_H+1][1+MAP_W+1];

int D[5][2]={ {0, 0}, {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
#define Dh (h+D[dir][0])
#define Dw (w+D[dir][1])

int _CalCount_dfs(int h, int w) // 计算 Line[h][w] 连续区域格数 
{
	flag[h][w]=1;
	int dir, sum=0;
	for(dir=1; dir<=4; dir++)
		if( flag[Dh][Dw]==0 ) 
			if( Line[Dh][Dw]==Line[h][w] )
				sum+=_CalCount_dfs(Dh, Dw);
	return sum+1; 
}

int CalCount(int h, int w) // 计算连接格数 
{
	int th, tw, cnt;
	for(th=1; th<=MAP_H; th++)
		for(tw=1; tw<=MAP_W; tw++)
			flag[th][tw]=0;
	if( 1<=h && h<=MAP_H && 1<=w && w<=MAP_W )return _CalCount_dfs(h, w);
	else // 如果传入的是不合法的数据 那么搜索到一个黑格再计数 
	{
		for(h=1; h<=MAP_H; h++)
			for(w=1; w<=MAP_W; w++)
				if( Line[h][w]==0 )
					return CalCount(h, w);
	}
	return 1;
}


#endif

