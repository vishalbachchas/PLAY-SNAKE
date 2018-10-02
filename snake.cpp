/*

          PLAY SNAKE
          
          
          MADE BY :- VISHAL BACHCHAS 2K16/SE/092
          
          
*/
          
#include <iostream>
#include <windows.h>
#include <vector>
typedef long long ll;
using namespace std;
ll MapW,MapH;
char Map[100][100]={

"########################################################",

"#                                                      #",

"#                                                      #",

"#                                                      #",

"#                                                      #",

"#                                                      #",

"#                                                      #",

"#                                                      #",

"#                                                      #",

"#                                                      #",

"#                                         @            #",

"#                                                      #",

"#                                                      #",

"########################################################"};

struct snakeBlock{

    ll x,y;

};



void gotoxy(ll x, ll y)

{

  COORD coord={x,y};

  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

}

void drawMap(vector <snakeBlock>snake)

{

    MapH=0;

    system("cls");

    for (ll i=0;Map[i][0];i++)

    {

        MapW=0;

        for (ll j = 0 ;Map[i][j];j++)

        {

            MapW++;

            if (Map[i][j]!=' ')

            {

                gotoxy(j,i);

                cout<<Map[i][j];

            }

        }

        MapH++;

    }

    for (ll i =0 ;i<snake.size();i++)

    {

        gotoxy(snake[i].x,snake[i].y);

        cout<<char (219);

    }

}



bool checkLose(ll x, ll y,vector <snakeBlock>&snake)

{

    if (Map[y][x]=='#')

        return true;

    if (snake.size()>3)

    {

        for (ll i = 3;i<snake.size();i++)

            if (snake[i].x==x&&snake[i].y==y)

                return true;

    }

    if (Map[y][x]=='@')

    {

        Map[y][x]=' ';

        snakeBlock newSnake;

        newSnake.x=snake[snake.size()-1].x;

        newSnake.y=snake[snake.size()-1].y;

        snake.push_back(newSnake);

        ll rx,ry;

        do{

            rx=rand()%MapW;

            ry=rand()%MapH;

        }while (checkLose(rx, ry,snake));

        Map[ry][rx]='@';

        drawMap(snake);

    }

    return false;

}



void snakeInit(ll x,ll y ,vector<snakeBlock> &snake)

{

    snakeBlock newSnake;

    newSnake.x=x;

    newSnake.y=y;

    snake.push_back(newSnake);

}



bool snakeMove(vector<snakeBlock>&snake,short dire[2])

{

    ll oldx,oldy,x,y;

    gotoxy(snake[snake.size()-1].x,snake[snake.size()-1].y);

    cout<<" ";

    oldx=snake[0].x;

    oldy=snake[0].y;

    snake[0].x+=dire[0];

    snake[0].y+=dire[1];

    gotoxy(snake[0].x,snake[0].y);

    cout<<char(219);

    if (snake.size()>1)

    {

        for (ll i = 1;i<snake.size();i++)

        {

            x=snake[i].x;

            y=snake[i].y;

            snake[i].x=oldx;

            snake[i].y=oldy;

            oldx=x;

            oldy=y;

        }

    }

    if (checkLose(snake[0].x,snake[0].y,snake))

        return true;

    return false;

}



ll main()

{

    bool GameIsRunning=true;

    ll GameSpeed=80;

    short dire[2]={0,1};

    vector<snakeBlock> snake;

    snakeInit(1,1,snake);

    drawMap(snake);

    while (GameIsRunning)

    {

        if (GetAsyncKeyState(VK_UP))

        {

            if (dire[1]==0)

            {

                dire[1]=-1;

                dire[0]=0;

            }

        }

        else if (GetAsyncKeyState(VK_DOWN))

        {

            if (dire[1]==0)

            {

                dire[1]=1;

                dire[0]=0;

            }

        }

        else if (GetAsyncKeyState(VK_LEFT))

        {

            if (dire[0]==0)

            {

                dire[1]=0;

                dire[0]=-1;

            }

        }

        else if (GetAsyncKeyState(VK_RIGHT))

        {

            if (dire[0]==0)

            {

                dire[1]=0;

                dire[0]=1;

            }

        }

        if(snakeMove(snake,dire))

        {

          system("cls");

          cout<<"Game Over"<<endl;

          system("pause");

          return 0;

        }

        Sleep(GameSpeed);

    }

}
