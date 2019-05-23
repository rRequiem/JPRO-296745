#include <stdio.h>
#include <stdlib.h>



int main()
{
    int i,j,c,d,p,x,y,z,m,n;
    char board[15][15];
    char board2[15][15];
    int counter;
    for(i=0;i<15;i++)
    {
        for(j=0;j<15;j++)
        {
            board[i][j] = '.';
        }
    }
    for(c = 0; c<15;c++){
        for(d=0;d<15;d++){
            printf("%c ", board[c][d]);
        }
        printf("\n");
    }
srand( time( NULL ) );

printf("Podaj ilosc zywych komorek (max 225)\n");
scanf("%d", &p);
for(z=0;z<p;z++)
{
    x = rand()%15;
    y = rand()%15;
    board[x][y] = 'X';
}
for(c = 0; c<15;c++){
        for(d=0;d<15;d++){
            printf("%c ", board[c][d]);
        }
        printf("\n");
    }

}
