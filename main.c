#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>


void cells(char board[16][16])
{
    board[1+8][1+8] = 'X';
    board[1+8][2+8] = 'X';
    board[1+8][3+8] = 'X';
    board[2+8][1+8] = 'X';
    board[3+8][2+8] = 'X';

}

void config(char board[31][31])
{
    FILE *plik = fopen("config.txt", "r");
    int i,j;
    for(i=1;i<30;i++)
    {
        for(j=1;j<30;j++)
        {
            char temp[31][31];
            fscanf(plik, "%s", &temp[i][j]);
            board[i][j] = temp[i][j];
        }
    }
    fclose(plik);
}

void random_cells(char board[31][31])
{
int p,z,x,y;
srand( time( NULL ) );
printf("Podaj ilosc zywych komorek (max 225)\n");
scanf("%d", &p);
for(z=0;z<p;z++)
{
    x = rand()%29+1;
    y = rand()%29+1;
    board[x][y] = 'X';
}
}

void delay(float seconds)
{
    int milli_seconds = 1000 * seconds;
    clock_t start_time = clock();
    while (clock() < start_time + milli_seconds);
}

void next_step(char board[31][31], int board2[31][31])
{
    int i,j,count=0;
    for(i=1;i<30;i++)
    {
        for(j=1;j<30;j++)
        {
            if(board[i-1][j-1] == 'X')
                count++;
            if(board[i-1][j] == 'X')
                count++;
            if(board[i-1][j+1] == 'X')
                count++;
            if(board[i][j-1] == 'X')
                count++;
            if(board[i][j+1] == 'X')
                count++;
            if(board[i+1][j-1] == 'X')
                count++;
            if(board[i+1][j] == 'X')
                count++;
            if(board[i+1][j+1] == 'X')
                count++;
            board2[i][j] = count;
            count = 0;

        }
    }
    for(i=0;i<31;i++)
    {
        for(j=0;j<31;j++)
        {
            if(board2[i][j] == 3)
                board[i][j] = 'X';
            else if(board2[i][j] == 2)
                board[i][j] = board[i][j];
            else
                board[i][j] = '.';
        }
    }

    system("cls");
    for(i=1;i<30;i++)
    {
        for(j=1;j<30;j++)
        {
            printf("%c ",board[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int i,j,c,d,m,n,seconds=1;
    char board[31][31];
    int board2[31][31];
    for(i=0;i<31;i++)
    {
        for(j=0;j<31;j++)
        {
            board[i][j] = '.';
        }
    }
    /*for(c = 0; c<16;c++){
        for(d=0;d<16;d++){
            printf("%c ", board[c][d]);
        }
        printf("\n");
    }*/

//random_cells(board);
config(board);

for(c = 1; c<30;c++){
        for(d=1;d<30;d++){
            printf("%c ", board[c][d]);
        }
        printf("\n");
    }
for(i=0;i<31;i++)
{
    for(j=0;j<31;j++)
    {
        board2[i][j] = 0;
    }
}
printf("Wcisnij dowolny klawisz by rozpoczac animacje\n");
system("pause");
while(1==1)
{
    delay(0.3);
    next_step(board,board2);
}

    /*for(c = 0; c<16;c++){
        for(d=0;d<16;d++){
            printf("%d ", board2[c][d]);
        }
        printf("\n");
    }*/
}
















 /*           count = count + (board[i-1][j-1] ? 'X' : '.');
            count = count + (board[i-1][j] ? 'X' : '.');
            count = count + (board[i-1][j+1] ? 'X' : '.');
            count = count + (board[i][j-1] ? 'X' : '.');
            count = count + (board[i][j+1] ? 'X' : '.');
            count = count + (board[i+1][j-1] ? 'X' : '.');
            count = count + (board[i+1][j] ? 'X' : '.');
            count = count + (board[i+1][j+1] ? 'X' : '.');
            board2[i][j] = count;
            count = 0;

FILE *plik = fopen("adrianos.txt", "r");
int n;
fscanf(plik, "%d", &n);
printf("%d", n);
fclose(plik);*/
