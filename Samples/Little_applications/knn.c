//Written by Abdur Rahman Biswas (B.Sc and M.Sc in CSE )

#include <stdio.h>
#include <stdlib.h>
int K = 3 ;
int X1 = 4;
int X2 = 7;
int n;
int distance[30];
int Rank[30];

int cmpfunc (const void * a, const void * b)
{
    return ( *(int*)a - *(int*)b );
}

int Color[30],Material[30],Classification[30];
int distance1[30];
void calculation()
{
    printf(" \ndistance\n");
    for(int i = 0 ; i<n ; i++)
    {

        //  distance[i] = ((X1 - Color[i])(X1 - Color[i]))+(X2 - Material[i])(X2 - Material[i]);
        distance[i]= (X1- Color[i] )*(X1 - Color[i]) + (X2 -Material[i])*(X2 - Material[i]);
        distance1[i] = distance[i];
        printf("%d\n",distance[i]);
    }
}
void ClassificationCalculation()
{
    printf("\nClassification\n\n");
    for(int i = 0 ; i< n ; i++)
    {
        if(Rank[i] < 4)
            printf("%d\n",Classification[i]);
        else
            printf("Nothing\n");

    }
}

void RankCalculation()
{
    printf("\nRank\n");
    for(int i = 0 ; i< n ; i++)
    {
        for(int j = 0 ; j < n; j++)
            if(distance1[i] == distance[j] )
            {
                Rank[i] = j+1;
                printf("\n%d",Rank[i]);
                break;
            }

    }

}
int main()
{
    freopen("input.txt","r",stdin);//if You want to notepad , with name input.txt

// printf(“Color Rank Classification\n”);

    scanf("%d", &n);
    for( int i = 0 ; i < n; i++ )
    {
        scanf("%d", &Color[i]);
        scanf("%d", &Material[i]);
        scanf("%d", &Classification[i]);

    }
    calculation();

    qsort(distance, n, sizeof(int), cmpfunc);

    RankCalculation();

    ClassificationCalculation();
    return(0);
}
