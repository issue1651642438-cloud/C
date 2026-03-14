#include<stdio.h>
#include<math.h>
#include<stdlib.h>

typedef struct
{
    double x;
    double y;
    int idex=0;
}position;

position pos[100];

double distance(position pos1,position pos2)
{
    return sqrt((pos1.x-pos2.x)*(pos1.x-pos2.x)+(pos1.y-pos2.y)*(pos1.y-pos2.y));
}


