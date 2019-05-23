#include <stdio.h>
#include <stdlib.h>


void next_step(char board[16][16], int board2[16][16])
{
    int i,j,count=0;
    for(i=1;i<15;i++)
    {
        for(j=1;j<15;j++)
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
}

int main()
{
    int i,j,c,d,p,x,y,z,m,n;
    char board[16][16];
    int board2[16][16];
    for(i=0;i<16;i++)
    {
        for(j=0;j<16;j++)
        {
            board[i][j] = '.';
        }
    }
    for(c = 0; c<16;c++){
        for(d=0;d<16;d++){
            printf("%c ", board[c][d]);
        }
        printf("\n");
    }
srand( time( NULL ) );

printf("Podaj ilosc zywych komorek (max 225)\n");
scanf("%d", &p);
for(z=0;z<p;z++)
{
    x = rand()%14+1;
    y = rand()%14+1;
    board[x][y] = 'X';
}
for(c = 0; c<16;c++){
        for(d=0;d<16;d++){
            printf("%c ", board[c][d]);
        }
        printf("\n");
    }
for(i=0;i<16;i++)
{
    for(j=0;j<16;j++)
    {
        board2[i][j] = 0;
    }
}
    next_step(board,board2);
    for(c = 0; c<16;c++){
        for(d=0;d<16;d++){
            printf("%d ", board2[c][d]);
        }
        printf("\n");
    }
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
            count = 0;*/
