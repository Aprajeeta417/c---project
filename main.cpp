#include<iostream>
#include<conio.h>
using namespace std;

bool gameover;
const int width = 20;
const int height = 20;
int x, y,fruitx,fruity,score;
enum eDirection
{
    STOP = 0,
    LEFT,
    RIGHT,
    UP,
    DOWN
};
eDirection dir;
void Setup(){
    gameover = false;
    dir = STOP;
    x = width / 2;
    y = height / 2;
    fruitx = rand() % width;
    fruity = rand() % height;
    score = 0;
}
void Draw(){
    system("cls");
    for (int i = 0; i < width+2;i++){
        cout << "#";
    }
    cout << endl;
    for (int i = 0; i < height;i++)
    {
        for (int j = 0; j < width;j++){
            if(j==0){
                cout << "#";
            }
            if(i==y && j==x)
                cout << "O";
            else if(i==fruity && j==fruitx)    
                cout << "F";


            if(j==width-1){
                cout << "#";
            }
        }
        cout << endl;
    }

    for (int i = 0; i < width; i++)
    {
        cout << "#";
    }
    cout << endl;
    cout << "score"<<score<<endl;
}
void Input(){
    if(_kbhit()){
        switch(_getch()){
            case 'a':
                dir = LEFT;
                break;
            case 'd':
                dir = RIGHT;
                break;
            case 'w':
                dir = UP;
                break;
            case 's':
                dir = DOWN;
                break;
            case 'x':
                gameover = true;
                break;
        }
    }
}
void Logic(){
    switch(dir)
    {
        case LEFT:
            x--;
            break;
        case RIGHT:
            x++;
            break;
        case UP:
            y--;
            break;     
        case DOWN:
            y++;
            break;
            
        default:
            break;
        }
        if(x>width || x<0 || y>height || y<0)
            gameover = true;
        if(x==fruitx && y==fruity){
            score = +10;
        }
}
int main(){
    Setup();
    while(!gameover){
        Draw();
        Input();
        Logic();
        //sleep(10);
    }
    return 0;
}
