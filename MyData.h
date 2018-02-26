
/*
MyData
*/


#ifndef _MYDATA

#define _MYDATA


#define MAP_H (8)
#define MAP_W (8)

int Map[1+MAP_H+1][1+MAP_W+1];

int cntofH[1+MAP_H+1][1+MAP_W+1];
int cntofW[1+MAP_H+1][1+MAP_W+1];
#define COUNTofH(h, w) (cntofH[h][Map[h][w]])
#define COUNTofW(h, w) (cntofW[Map[h][w]][w])


int Line[1+MAP_H+1][1+MAP_W+1];
int cntofBlack=0;


#endif

