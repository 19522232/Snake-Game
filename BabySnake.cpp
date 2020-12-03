#include <iostream>
#include "Mylib.h"
using namespace std;
struct Point
{
    int x,y;
};
int Length_Init=4;
Point Snake[100];
Point Food;
void DrawTopWall()
{
    int x =10, y=1;
    while(x<100)
    {
        gotoXY(x,y);
        cout<<"x";
        x++;
    }
}
void DrawBottomWall()
{
    int x =10, y=26;
    while(x<100)
    {
        gotoXY(x,y);
        cout<<"x";
        x++;
    }
}
void DrawRightWall()
{
    int x =100, y=1;
    while(y<=26)
    {
        gotoXY(x,y);
        cout<<"x";
        y++;
    }
}
void DrawLeftWall()
{
    int x =10, y=1;
    while(y<=26)
    {
        gotoXY(x,y);
        cout<<"x";
        y++;
    }
}
void Init()
{
    DrawBottomWall();
    DrawLeftWall();
    DrawRightWall();
    DrawTopWall();
}
void Draw_Snake(Point Snake[])
{
    for(int i=0;i<Length_Init;i++)
    {
        gotoXY(Snake[i].x,Snake[i].y);
        if(i==0)
        {
            cout<<"]";
        }
        else{
            cout<<"=";
        }
    }
}
void Create_Snake(Point Snake[])
{
    int x=50,y=13;
    for(int i=0;i<Length_Init;i++)
    {
        Snake[i].x=x;
        Snake[i].y=y;
        x--;
    }
}
int main()
{
    Init();
    Create_Snake(Snake);
    Draw_Snake(Snake);
    _getch();
}

