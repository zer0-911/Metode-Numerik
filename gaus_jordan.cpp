#include <iostream>
#include <math.h>
#include <stdio.h>

using namespace std;

int n, i, j, k, l;
double f, sum;
double X[50][51], x[50], a[50];

void input()
{
    printf("Input jumlah ordo : ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n + 1; j++)
        {
            printf("matrik X[%d][%d]:", i + 1, j + 1);
            scanf("%lf", &X[i][j]);
        }
        printf("\n");
    }
    printf("Matrik Inputan(X):\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j <= n; j++)
        {
            if(j<n)
            {
                printf("%g  ", X[i][j]);
            }
            else
            {
                printf("|| %g  ", X[i][j]);
            }
        }
        printf("\n");
    }
}
void iterasi()
{
    printf("\nProses Gauss-Jordan : \n");
    for (k = 0; k < n; k++)
    {
        float a = X[k][k];
        for (i = k; i < n + 1; i++)
        {
            X[k][i] = X[k][i] / a;
        }
        for (i = 0; i < n; i++)
        {
            if (i != k)
            {
                f = X[i][k] / X[k][k];
                for (j = 0; j < n + 1; j++)
                {
                    X[i][j] = X[i][j] - f * X[k][j];
                }
            }
        }
        printf("\nIterasi ke %d", k + 1);
        puts("");
        for (j = 0; j < n; j++)
        {
            for (l = 0; l < n; l++)
            {
                printf("%f\t", X[j][l]);
            }
            printf("|| %f", X[j][n]);
            puts("");
        }
    }
    for (i = 0; i < n; i++)
    {
        a[i] = X[i][n];
    }
}

void hitung()
{
    printf("\nSolusi\n");
    x[n - 1] = a[n - 1] / X[n - 1][n - 1];
    for (i = n - 2; i >= 0; i--)
    {
        sum = 0;
        for (j = i + 1; j <= n; j++)
        {
            sum = sum + X[i][j] * x[j];
        }
        x[i] = (a[i] - sum) / X[i][i];
    }
    for (i = 0; i < n; i++)
    {
        printf("X[%d] = %f\n", i + 1, x[i]);
    }
}


int main()
{
    input();
    iterasi();
    hitung();
    return 0;
}