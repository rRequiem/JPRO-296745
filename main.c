#include <stdio.h>
#include <stdlib.h>
#include<time.h>



void delay(float seconds){

    int milli_seconds = 1000 * seconds;
    clock_t start_time = clock();
    while (clock() < start_time + milli_seconds);
}


void start(char tab[31][31])
{
    int x,y,z,c;
    printf("Podaj liczbe=");
    scanf("%d",&c);
    srand(time(NULL));
    for(z=0;z<c;z++)
    {
        x=rand()%29+1;
        y=rand()%29+1;
        tab[x][y]='X';
    }
    for(int i=0;i<30;i++)
    {
        for(int j=0;j<30;j++)
            {
            printf("%c ",tab[i][j]);
            }
            printf("\n");
    }

}

void fill(char tab[31][31])
{

    for(int i=0;i<31;i++)
    {
        for(int j=0;j<31;j++)
        {
            tab[i][j]='.';
        }
    }
    for(int i=0;i<30;i++)
    {

        for(int j=0;j<30;j++)
        {
            printf("%c ",tab[i][j]);
        }
        printf("\n");
    }
}



void sasiad(char tab[31][31], int tab2[31][31])
{

int x,y,s;
s=0;
    for(x=0;x<31;x++)
    {
        for(y=0;y<31;y++)
        {
    if(tab[x+1][y]=='X')
        s++;
    if(tab[x][y+1]=='X')
        s++;
    if(tab[x-1][y]=='X')
        s++;
    if(tab[x+1][y+1]=='X')
        s++;
    if(tab[x+1][y-1]=='X')
        s++;
    if(tab[x-1][y+1]=='X')
        s++;
    if(tab[x][y-1]=='X')
        s++;
    if(tab[x-1][y-1]=='X')
        s++;
    tab2[x][y]=s++;
    s=0;

        }
    }

system("cls");

for( x=0;x<31;x++)
{
    for(y=0; y<31;y++)
        {
    if(tab2[x][y]==3)
        tab[x][y]='X';
    else if(tab2[x][y]==2)
        tab[x][y]=tab[x][y];
   else
        tab[x][y]='.';
        }
}

   for(x=0;x<30;x++)
    {

            for(y=0;y<30;y++){
                printf("%c ",tab[x][y]);
        }
        printf("\n");
    }

}

int main()
{
char tab[31][31];
int tab2[31][31];

fill(tab);
start(tab);
printf("\n \n");
//tablica();
while(1==1)
{
delay(1);
sasiad(tab,tab2);

}
}
