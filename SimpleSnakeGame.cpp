#include<iostream>
#include<conio.h>
using namespace std;

//gobal variable
bool gameOver;

//map dimensions
const int width = 20;
const int height= 20;

//Basic variables needed.
int x,y,fruitX,fruitY,score;

//snake tail
//we are going to use array for tail
int tailX[100],tailY[100];
int ntail;//length of tail

//to track direction of the snake.
enum eDirection{ STOP=0, LEFT, RIGHT, UP, DOWN};
eDirection dir; 

void Setup()
{
    gameOver = false;
    dir=STOP;

    //snake head at center;
    x=width/2;
    y=height/2;

    //fruit location(random=rand())
    
    fruitX=rand()%width;
    fruitY=rand()%height;
    
    score=0;
}

void Draw()
{
    system("cls");//clears console window.
    
    //borders
    for(int i=0;i<width;i++)
        cout<<"#";
    
    cout<<endl;
    for(int i=0;i<height;i++)
    {
        for(int j=0;j<width;j++)
        {
            if(j==0)
                cout<<"#";
            if(i== y && j==x)
                cout<<"O";
            else if(i==fruitY && j==fruitX)
                cout<<"F";
            cout<<" ";
            
            if(j=width-1)
                cout<<"#";

        }
        cout<<endl;
    }

    for(int i=0;i<width+2;i++)
        cout<<"#";
    cout<<endl<<endl;
    cout<<"SCORE : "<<score<<endl;
}

void Input()
{
    //we need to include two funtons that are asynchronus funtuons.
    //to get characters from console window.
    if(_kbhit())//returns true if keyboard key is pressed else false.
    {
        switch(_getch())
        {
            //LEFT
            case 'a':
                dir=LEFT;
                break;
            
            //RIGHT
            case 'd':
                dir=RIGHT;
                break;
            
            //UP
            case 'w':
                dir=UP;
                break;
            
            //DOWN
            case 's':
                dir=DOWN;
                break;
            //exit game.
            case 'x':
                gameOver=true;
                break;
            default:
                break;
        }
        
        //if snake run over boundaries of map.
        if(x>width || x<0 || y>height || y<0)
            gameOver=true;
        
        //snake eats food
        if(x==fruitX && y==fruitY)
        {
            score+=10;
            
            fruitX=rand()%width;
            fruitY=rand()%height;
        }
    }
}

void Logic()
{
    switch(dir)
    {
        case LEFT:
            x--;
            break;
        case RIGHT:
            x++;
            break;
        case UP:
            y++;
            break;
        case DOWN:
            y--;
            break;
        

    }
}

int main()
{
    Setup();
    while(!gameOver)
    {
        Draw();
        Logic();
        Input();
        //sleep(10);
    }
}