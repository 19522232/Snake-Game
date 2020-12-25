#include <iostream>
#include <windows.h>
#include "Mylib.h"
using namespace std;
struct Point
{
    int x, y;
};
int Length_Init = 4;
int n;
int score = 0;
Point Snake[100];
Point Food;
int level = 500;
void SetColorBackground(int k)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, k);
}
void InitConsole()
{
    HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r); //stores the console's current dimensions
    MoveWindow(console, r.left, r.top, 500, 500, TRUE);
}

void DrawTopWall()
{
    int x = 10, y = 1;
    while (x <= 40)
    {
        gotoXY(x, y);
        cout << "x";
        x++;
    }
}
void DrawBottomWall()
{
    int x = 10, y = 20;
    while (x <= 40)
    {
        gotoXY(x, y);
        cout << "x";
        x++;
    }
}
void DrawRightWall()
{
    int x = 40, y = 1;
    while (y <= 20)
    {
        gotoXY(x, y);
        cout << "x";
        y++;
    }
}
void DrawLeftWall()
{
    int x = 10, y = 1;
    while (y <= 20)
    {
        gotoXY(x, y);
        cout << "x";
        y++;
    }
}
void Init()
{
    SetColorBackground(100);

    DrawBottomWall();
    DrawLeftWall();
    DrawRightWall();
    DrawTopWall();

    SetColorBackground(263);
}
bool CheckDirection(int Way, int LastWay)
{
    if (Way == 1 && LastWay == 3)
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
    for (int i = 0; i < Length_Init; i++)
    {
        gotoXY(Snake[i].x, Snake[i].y);
        if (i == 0)
        {
            cout << "O";
        }
        else {
            cout << "o";
        }
    }
}
void Create_Snake(Point Snake[])
{
    int x = 20, y = 13;
    score = 0;
    for (int i = 0; i < Length_Init; i++)
    {
        Snake[i].x = x;
        Snake[i].y = y;
        x--;
    }
}
bool InSnake(Point A)
{
    for (int i = 1; i < n; i++)
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
    } while (InSnake(Food) || Food.x == Snake[0].x && Food.y == Snake[0].y);
    gotoXY(Food.x, Food.y);
    SetColor(3);
    cout << "$";
    SetColor(7);
}
bool IsCollisionOwn()
{
    return InSnake(Snake[0]);
}
void Move(int Direction)
{
    if (Snake[0].x == Food.x && Snake[0].y == Food.y)
    {
        Snake[n] = Snake[n - 1];
        n++;
        score++;
        gotoXY(43, 5);
        cout << "SCORE: " << score;
        CreateFood();
    }
    else
    {
        gotoXY(Snake[n - 1].x, Snake[n - 1].y);
        cout << " ";
    }
    for (int i = n - 1; i > 0; i--)
    {
        Snake[i] = Snake[i - 1];
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
    gotoXY(Snake[0].x, Snake[0].y);
    cout << "O";
    gotoXY(Snake[1].x, Snake[1].y);
    cout << "o";

}
void DrawString(string s)
{
    SetColorBackground(112);
    cout << s << endl;
    SetColorBackground(263);
}
void DrawMenu(int selected)
{
    //SetColorBackground(112);
    //SetColor(5);
    gotoXY(20, 6);
    cout << "MENU" << endl;

    gotoXY(17, 7);
    if (selected == 1)
        DrawString("PLAY GAME");
    else cout << "PLAY GAME" << endl;

    gotoXY(17, 8);
    if (selected == 2)
        DrawString("LEVEL");
    else cout << "LEVEL" << endl;

    gotoXY(17, 9);
    if (selected == 3)
        DrawString("EXIT");
    else cout << "EXIT" << endl;
}
void DrawLevelMenu(int selected)
{
    gotoXY(20, 6);
    cout << "LEVEL" << endl;

    gotoXY(17, 7);
    if (selected == 1)
        DrawString("EASY");
    else cout << "EASY" << endl;

    gotoXY(17, 8);
    if (selected == 2)
        DrawString("NORMAL");
    else cout << "NORMAL" << endl;

    gotoXY(17, 9);
    if (selected == 3)
        DrawString("HARD");
    else cout << "HARD" << endl;

    gotoXY(17, 11);
    if (selected == 4)
        DrawString("BACK");
    else cout << "BACK" << endl;
}
void StartGame()
{
    gotoXY(43, 5);
    cout << "SCORE: " << score;
    gotoXY(3, 23);
    cout << "Press Space to Pause ";
    gotoXY(3, 24);
    cout << "Press Esc to back to MainMenu ";
    gotoXY(3, 26);
    cout << "Press Tab to exit game ";
    CreateFood();
    n = Length_Init;
    int key;
    int CurrentDirection = 2;
    while (1)
    {
        Sleep(level);
        key = inputKey();
        switch (key)
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
        case 32:
            gotoXY(0, 0);
            system("pause");
            gotoXY(0, 0);
            cout << "                                                    ";
            break;
        case 27:
            return;
            break;
        case 9:
            gotoXY(3, 28);
            exit(0);
            break;
        }
        Move(CurrentDirection);
        if (IsCollisionOwn() || IsCollision(Snake[0]))
            break;
    }
    gotoXY(0, 0);
    cout << "YOU LOSE! Your score: " << score << "   ";
    system("pause");
}
int GetcurrentLevel()
{
    if (level == 500)
        return 1;
    else if (level == 350)
        return 2;
    else return 3;
}

void Playgame()
{
    int selection = 1;
    bool isMainMenu = true;
    int key;
    while (1)
    {
        Sleep(200);
        key = inputKey();
        if (isMainMenu)
        {
            if (key == 1072)
            {
                selection--;
                if (selection == 0)
                    selection = 3;
                DrawMenu(selection);
            }
            else if (key == 1080)
            {
                selection++;
                if (selection == 4)
                    selection = 1;
                DrawMenu(selection);
            }
            else if (key == 13)
            {
                if (selection == 1)
                {
                    system("cls");
                    srand(time(NULL));
                    Init();
                    Create_Snake(Snake);
                    Draw_Snake(Snake);
                    StartGame();
                    system("cls");
                    DrawMenu(1);
                }
                else if (selection == 2)
                {
                    selection = GetcurrentLevel();
                    isMainMenu = false;
                    system("cls");
                    DrawLevelMenu(selection);
                }
                else exit(0);
            }
        }
        else
        {
            if (key == 1072)
            {
                selection--;
                if (selection == 0)
                    selection = 4;
                DrawLevelMenu(selection);
            }
            else if (key == 1080)
            {
                selection++;
                if (selection == 5)
                    selection = 1;
                DrawLevelMenu(selection);
            }
            else if (key == 13)
            {
                switch (selection)
                {
                case 1:
                    level = 500;
                    isMainMenu = true;
                    selection = 2;
                    system("cls");
                    DrawMenu(2);
                    break;
                case 2:
                    level = 350;
                    isMainMenu = true;
                    selection = 2;
                    system("cls");
                    DrawMenu(2);
                    break;
                case 3:
                    level = 200;
                    isMainMenu = true;
                    selection = 2;
                    system("cls");
                    DrawMenu(2);
                    break;
                case 4:
                    isMainMenu = true;
                    selection = 2;
                    system("cls");
                    DrawMenu(2);
                    break;
                }
            }
        }
    }
}


int main()
{
    InitConsole();
    DrawMenu(1);
    Playgame();
    //_getch();
}
