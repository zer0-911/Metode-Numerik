#include <cstdlib>
#include <iostream>
#include <math.h>

using namespace std;

double f(double x) //fungsi persamaan
{
       return (3*cos(x) - exp(x) + 3*x*x + 1);
}

double ff(double x) //turunan fungsi f(x)
{
    return (-3*sin(x)-x*exp(x)+6*x);
}

void NR(double aerr, int maxitr, double a)
{
     int i = 0;
     double b, prev;
     while (i <= maxitr)
     {
           b = a - (f(a))/ff(a);
           cout << "Iter " << i << ": x = " << b << endl;
           i++;
           if (fabs(b - a) < aerr)
              break;
           a = b;
     }
    
}

int main()
{
    double aerr, a, b;
    int maxitr;
    cout << "Masukkan Toleransi error" << endl;
    cin >> aerr;
    cout << "Masukkan iterasi Maksimum" << endl;
    cin >> maxitr;
    cout << "Masukkan Tebakan awal" << endl;
    cin >> a;
    NR(aerr, maxitr, a);
    
    return 0;
}