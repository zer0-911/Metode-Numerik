#include<stdio.h>
#include<stdlib.h>

void print(int n,int m,float mat[6][6])
{
    for(int i=0; i<n; i++) 
	{
      	for(int j=0; j<m; j++) 
     	{
     		printf("%.3f ", mat[i][j]);
     	}
    	printf("\n");
  	}
}

void gauss(int n,float mat[6][6])
{
    //back-substitution
    printf("\n Solusi \n");
    int x=n;
    float nilai[x];

    for(int i=x-1; i>=0;i--)
    {
        float total=0;
        for(int j=x-1;j>i;j--)
        {
            total+=mat[i][j]*nilai[j];
        }
        nilai[i]=mat[i][x]-total;
    }
    for(int i=0;i<x;i++)
    {
        printf("X%d : %.3f",i+1,nilai[i]);
        printf("\n");
    }
}

void iter(int n,int m,float mat[6][6],int ulang)
{
    //forward-elimination
    float ratio=mat[ulang][ulang];

    for(int i=0;i<m;i++)
	 {
		 mat[ulang][i]/=ratio;
	 }
    for(int i=ulang+1;i<n;i++)
    {
        float a=mat[i][ulang];
        for(int j=ulang;j<m;j++)
        {
            mat[i][j]-=a*mat[ulang][j];
        }
    }

    printf("\n");
    printf("Iterasi ke %d",ulang+1);
    printf("\n");

    print(n,m,mat);
    ulang++;
    if(ulang<n){
        printf("\n");
        iter(n,m,mat,ulang);
    }
    if(ulang==n)
    {
        gauss(n,mat);
    }
}

int main()
{
    int i,j;
    int n,m;
    float mat[6][6];
    int ulang=0;

    printf("masukkan banyak variabel yang dicari(maks 5) : ");
    scanf("%d",&n);
    if(n>5)
    {
        n=5;
    }
    m=n+1;
    printf("Masukkan nilai untuk\n");
    for(i=0 ; i < n ; i++)
	{
        for(j=0 ; j <m ; j++)
        {
         printf("[%d][%d]:", i+1, j+1);
         scanf("%f", &mat[i][j]);
        }
    }

    printf("\n");
    printf("MATRIKS AWAL");
    printf("\n");

    print(n,m,mat);
    iter(n,m,mat,ulang);
   
    return 0;
}