#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <stdbool.h>

bool gameOver;
const int width = 50;
const int height = 30;
int x, y, fruitX, fruitY, score;
enum eDirection {STOP = 0, LEFT, RIGHT, UP, DOWN};
enum eDirection dir;

void Setup()
{
    gameOver = false;
    dir = STOP;
    x = width/2;
    y = height/2;
    fruitX = rand()%width;
    fruitY = rand()%height;
    score;
}

void Draw()
{
    system("cls");

    for(int i = 0; i < width+2; i++){
        printf("#");
    }
    printf("\n");

    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++){
            if(j == 0){
                printf("#");
            }

            if(i == y && j == x){
                printf("O");
            }else if(i == fruitY && j == fruitX){
                printf("F");
            }else {
                printf(" ");
            }

            if(j == width-1){
                printf("#");
            }
        }
        printf("\n");
    }

     for(int i = 0; i < width+2; i++){
        printf("#");
    }
    printf("\n");
    printf("score:%i\n", score);
}

void Input()
{
    if (_kbhit()){
        switch(_getch())
        {
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
                gameOver = true;
                break;
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
            y--;
            break;
        case DOWN:
            y++;
            break;
        default:
            break;
    }
    if(x > width || x < 0 || y > height || y < 0){
        gameOver = true;
    }
    if(x == fruitX && y == fruitY){
        score = score + 10;
        fruitX = rand()%width;
        fruitY = rand()%height;
    }
}

int main()
{
    Setup();

    while (!gameOver)
    {
        Draw();
        Input();
        Logic();
    }
    return 0;
}
