#include <iostream>
#include "Mylib.h"
using namespace std;
struct Point
{
    int x,y;
};
int Length_Init=4;
int n;
Point Snake[100];
Point Food;
void DrawTopWall()
{
    int x =10, y=1;
    while(x<=40)
    {
        gotoXY(x,y);
        cout<<"x";
        x++;
    }
}
void DrawBottomWall()
{
    int x =10, y=20;
    while(x<=40)
    {
        gotoXY(x,y);
        cout<<"x";
        x++;
    }
}
void DrawRightWall()
{
    int x =40, y=1;
    while(y<=20)
    {
        gotoXY(x,y);
        cout<<"x";
        y++;
    }
}
void DrawLeftWall()
{
    int x =10, y=1;
    while(y<=20)
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
bool CheckDirection(int Way, int LastWay)
{
    if (Way == 1 && LastWay == 3 )
        return false;
    if (Way == 2 && LastWay == 4)
        return false;
    if (Way == 3 && LastWay == 1)
        return false;
    if (Way == 4 && LastWay == 2)
        return false;
    return true;
}
bool IsCollision(Point Head)
{
    if (Head.x == 10 || Head.x == 40)
        return true;
    if (Head.y == 1 || Head.y == 20)
        return true;
    return false;
}
void Draw_Snake(Point Snake[])
{
    for(int i=0;i<Length_Init;i++)
    {
        gotoXY(Snake[i].x,Snake[i].y);
        if(i==0)
        {
            cout<<"O";
        }
        else{
            cout<<"o";
        }
    }
}
void Create_Snake(Point Snake[])
{
    int x=20,y=13;
    for(int i=0;i<Length_Init;i++)
    {
        Snake[i].x=x;
        Snake[i].y=y;
        x--;
    }
}
bool InSnake(Point A)
{
    for (int i=1; i<n; i++)
    {
        if (A.x == Snake[i].x && A.y == Snake[i].y)
            return true;
    }
    return false;
}
void CreateFood()
{
    do
    {
        Food.x = rand() % 28 + 11;
        Food.y = rand() % 18 + 2;
    }
    while (InSnake(Food) || Food.x == Snake[0].x && Food.y == Snake[0].y);
    gotoXY(Food.x, Food.y);
    cout<<"$";
}
bool IsCollisionOwn()
{
    return InSnake(Snake[0]);
}
void Move(int Direction)
{
    if (Snake[0].x == Food.x && Snake[0].y == Food.y)
    {
        Snake[n] = Snake[n-1];
        n++;
        CreateFood();
    }
    else
    {
        gotoXY(Snake[n-1].x, Snake[n-1].y);
        cout<<" ";
    }
    for (int i=n-1; i>0; i--)
    {
        Snake[i] = Snake[i-1];
    }
    switch (Direction)
    {
        case 1:
            Snake[0].y--;
            break;
        case 2:
            Snake[0].x++;
            break;
        case 3:
            Snake[0].y++;
            break;
        case 4:
            Snake[0].x--;
    }
    gotoXY(Snake[0].x,Snake[0].y);
    cout<<"O";
    gotoXY(Snake[1].x,Snake[1].y);
    cout<<"o";

}


void StartGame()
{
    CreateFood();
    n = Length_Init;
    int key;
    int CurrentDirection = 2;
    while(1)
    {
        Sleep(200);
        key = inputKey();
        switch(key)
        {
            case 1072:
                if (!CheckDirection(1, CurrentDirection))
                    break;
                CurrentDirection = 1;
                break;
            case 1077:
                if (!CheckDirection(2, CurrentDirection))
                    break;
                CurrentDirection = 2;
                break;
            case 1080:
                if (!CheckDirection(3, CurrentDirection))
                    break;
                CurrentDirection = 3;
                break;
            case 1075:
                if (!CheckDirection(4, CurrentDirection))
                    break;
                CurrentDirection = 4;
                break;
        }
        Move(CurrentDirection);
        if (IsCollisionOwn() || IsCollision(Snake[0]))
            break;
    }
    gotoXY(0,0);
    cout<<"YOU LOSE! Press Enter to restart game!";
}
void Playgame()
{
    gotoXY(0,0);
    cout<<"Press Enter to start game!";
    int key;
    while(1)
    {
        Sleep(500);
        key = inputKey();
        if( key == 13)
        {
            system("cls");
            srand(time(NULL));
            Init();
            Create_Snake(Snake);
            Draw_Snake(Snake);
            StartGame();
        }
    }
}
int main()
{

    Playgame();
    _getch();
}
