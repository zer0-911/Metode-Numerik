#include <stdio.h>         
#include <iostream>    
#include <conio.h>            
#include <math.h>            

using namespace std;
float secant(float x)
{
 float y;
   y=3*cos(x) - exp(x) + 3*x*x + 1;
   return y;
}

int main ()                  
{
	int max_iter,n=0;
	float x[20], tol, er;

	cout<<"=================================================\n";
	cout<<"|Menentukan Akar Persamaan dengan Metode Secant|"<<endl;
   	cout<<"=================================================\n\n";
	printf("   Tentukan Akar Persamaan dari y= 3*cos(x) - exp(x) + 3*x*x + 1\n\n");
	cout<<"-------------------------------------------------\n\n";
	printf("Input Batas Awal X(n-1)\t : "); scanf("%f", &x[0]);
	printf("Input Batas Akhir X(n)\t : "); scanf("%f", &x[1]);
	printf("Input Toleransi eror (e) : "); scanf("%f", &tol);
	printf("Input Iterasi Maksimum   : "); scanf("%d", &max_iter);
	printf("\n");
 	printf("   n X(n-1)\t X(n)\t X(n+1) f(X(n+1)) eror\n");

	do
	{
		n++;/*Pengulangan untuk nomor iterasi*/
		x[n+1]=((x[n]*secant(x[n-1]))-(x[n-1]*secant(x[n])))/(secant(x[n-1])-secant(x[n]));
		er=fabs(((x[n+1])-(x[n]))/(x[n+1]));
		printf("%3d %8.5f %8.5f %8.5f %8.5f %8.3f\n", n,x[n-1],x[n],x[n+1],secant(x[n+1]),er);
	}
	while(fabs(secant(x[n+1]))>tol);
	if(n <= max_iter)
	{
		printf("\n");
		printf("Toleransi terpenuhi\n");
		printf("akarnya yaitu = %f\n",x[n+1]);
		printf("\n");
	}
 	else
	printf("Toleransi tidak terpenuhi");
	getch();

}