

// ��

#include <stdio.h>

//#define MAP_H (4)
//#define MAP_W (4)
#define MAP_H (8)
#define MAP_W (8)

/*
int Map[1+MAP_H+1][1+MAP_W+1]={ 
{-1,-1,-1,-1,-1,-1}, 
{-1, 1, 2, 2, 3,-1}, 
{-1, 3, 2, 4, 1,-1},
{-1, 3, 4, 3, 2,-1},
{-1, 4, 1, 3, 2,-1}, 
{-1,-1,-1,-1,-1,-1} 
};
*/
int Map[1+MAP_H+1][1+MAP_W+1];

/*
int cntofH[1+MAP_H+1][1+MAP_W+1]={ 
{ 0, 0, 0, 0, 0, 0 }, 
{ 0, 1, 2, 1, 0, 0 }, 
{ 0, 1, 1, 1, 1, 0 }, 
{ 0, 0, 1, 2, 1, 0 }, 
{ 0, 1, 1, 1, 1, 0 }, 
{ 0, 0, 0, 0, 0, 0 } 
};
*/
int cntofH[1+MAP_H+1][1+MAP_W+1];

/*
int cntofW[1+MAP_H+1][1+MAP_W+1]={
{ 0, 0, 0, 0, 0, 0 }, 
{ 0, 1, 1, 0, 1, 0 }, 
{ 0, 0, 2, 1, 2, 0 }, 
{ 0, 2, 0, 2, 1, 0 }, 
{ 0, 1, 1, 1, 0, 0 }, 
{ 0, 0, 0, 0, 0, 0 } 
};
*/
int cntofW[1+MAP_H+1][1+MAP_W+1];

#define COUNTofH(h, w) (cntofH[h][Map[h][w]])
#define COUNTofW(h, w) (cntofW[Map[h][w]][w])


/*
int Line[1+MAP_H+1][1+MAP_W+1]={ 
{-9,-5,-5,-5,-5,-8}, 
{-4, 0, 1, 0, 0,-4}, 
{-4, 0, 0, 0, 0,-4}, 
{-4, 1, 0, 1, 0,-4}, 
{-4, 0, 0, 0, 1,-4}, 
{-7,-5,-5,-5,-5,-6} 
}; 
*/
int Line[1+MAP_H+1][1+MAP_W+1];

int cntofBlack=4;


/*
map : 
1 2 2 3
3 2 4 1
3 4 3 2
4 1 3 2

line : 
0 1 0 0
0 0 0 0
1 0 1 0
0 0 0 1

*/



/*
int flag[1+MAP_H+1][1+MAP_W+1]={ 
{-1,-1,-1,-1,-1,-1}, 
{-1, 0, 0, 0, 0,-1}, 
{-1, 0, 0, 0, 0,-1}, 
{-1, 0, 0, 0, 0,-1}, 
{-1, 0, 0, 0, 0,-1}, 
{-1,-1,-1,-1,-1,-1},  
};
*/
int flag[1+MAP_H+1][1+MAP_W+1];


int D[5][2]={ {0, 0}, {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
#define Dh (h+D[dir][0])
#define Dw (w+D[dir][1])

int _CalCount_dfs(int h, int w) // ���� Line[h][w] ����������� 
{
	flag[h][w]=1;
	int dir, sum=0;
	for(dir=1; dir<=4; dir++)
		if( flag[Dh][Dw]==0 ) 
			if( Line[Dh][Dw]==Line[h][w] )
				sum+=_CalCount_dfs(Dh, Dw);
	return sum+1; 
}

int CalCount(int h, int w) // �������Ӹ��� 
{
	int th, tw, cnt;
	for(th=1; th<=MAP_H; th++)
		for(tw=1; tw<=MAP_W; tw++)
			flag[th][tw]=0;
	if( 1<=h && h<=MAP_H && 1<=w && w<=MAP_W )return _CalCount_dfs(h, w);
	else // ���������ǲ��Ϸ������� ��ô������һ���ڸ��ټ��� 
	{
		for(h=1; h<=MAP_H; h++)
			for(w=1; w<=MAP_W; w++)
				if( Line[h][w]==0 )
					return CalCount(h, w);
	}
	return 1;
}



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



void InitMap()
{
	int h, w, n;
	
	// �� 
	for(h=1; h<=MAP_H; h++)
		for(w=1; w<=MAP_W; w++)
			Map[h][w]=0;
	
	// �� ( ��, �� ) 
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
	
	// �� 
	n=-9;
	for(h=0; h<=MAP_H+1; h+=MAP_H+1)
		for(w=0; w<=MAP_W+1; w+=MAP_W+1)
			Map[h][w]= (n++);
	
}

void InitLine()
{
	int h, w, n;
	
	// �� 
	for(h=1; h<=MAP_H; h++)
		for(w=1; w<=MAP_W; w++)
			Line[h][w]=0;
	cntofBlack=0;
	
	// �� ( ��, �� ) 
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
	
	// �� 
	n=-9;
	for(h=0; h<=MAP_H+1; h+=MAP_H+1)
		for(w=0; w<=MAP_W+1; w+=MAP_W+1)
			Line[h][w]=	(n++);
}


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
	
	// �����ж� t �Ϸ�֮����ִ�� 
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
			     if( Map[h][w]==-9 )printf("��");
			else if( Map[h][w]==-8 )printf("��");
			else if( Map[h][w]==-7 )printf("��");
			else if( Map[h][w]==-6 )printf("��");
			else if( Map[h][w]==-5 )printf("��");
			else if( Map[h][w]==-4 )printf("��");
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
				 if( Line[h][w]== 1 )printf("��");
			else if( Line[h][w]==-9 )printf("��");
			else if( Line[h][w]==-8 )printf("��");
			else if( Line[h][w]==-7 )printf("��");
			else if( Line[h][w]==-6 )printf("��");
			else if( Line[h][w]==-5 )printf("��");
			else if( Line[h][w]==-4 )printf("��");
			else printf("%-2d", Map[h][w]);
		}
		printf("\n");
	}
}


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
			Line[h][w]=1; // �Ƿ���Ҫ���ж� Line[h][w]==0 
			cntofBlack++;
			COUNTofH(h, w)--; // �Ƿ�֮ǰ��Ҫ�жϷ�0 
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
	
	
	if( _solve_(1, 1)==1 )
	{
		PrintLine();
		return 1;
	}
	else 
	{
		printf("�޽⣡\n");
		return 0;
	}
}



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
	
	
	return 0;
}


