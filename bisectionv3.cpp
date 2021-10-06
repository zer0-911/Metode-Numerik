
#include <stdio.h>


void titiktengah (float xl, float xu, float &xr)
{
    xr = (xl+xu)/2;
}

void hasil (float x, float &eqResult)
{
    eqResult = (2*x*x)-(5*x)+2;
}

void proses (float &xl, float &xu, float &xr, int &iterasi, int &flag1, int &flag2, float &starterxl, float &starterxu)
{
    float eqResult1, eqResult2, eqResult3;
    iterasi += 1;
    hasil(xl,eqResult1);
    hasil(xu,eqResult3);
    if (flag1 == 0)
    {
        flag1 += 1;
        if (eqResult1==0 && eqResult3==0)
        {
            printf("Kedua batas yang dimasukkan adalah akar persamaan\n");
            printf("Akar persamaannya adalah : %f dan %f\n", xl, xu);
            return;
        }
        else if (eqResult1==0)
        {
            printf("Batas bawah yang dimasukkan adalah salah satu akar persamaan\n");
            printf("Salah satu akar persamaan antara interval yang dimasukkan adalah: %f\n", xl);
            printf("Lanjutkan untuk mencari akar persamaan lainnya\n\n");
            xl += 0.1;
            flag1 += 1;
        }
        else if (eqResult3==0)
        {
            printf("Batas atas yang dimasukkan adalah salah satu akar persamaan\n");
            printf("Salah satu akar persamaan antara interval yang dimasukkan adalah: %f\n", xu);
            printf("Lanjutkan untuk mencari akar persamaan lainnya\n\n");
            xu -= 0.1;
            flag1 += 1;
        }
    }
    titiktengah(xl,xu,xr);
    hasil(xl,eqResult1);
    hasil(xu,eqResult3);
    hasil(xr,eqResult2);
    printf("Iterasi ke %d -->", iterasi);
    printf("xl = %f  ", xl);
    printf("xu = %f  ", xu);
    printf("xr = %f  \n", xr);
    if (eqResult1*eqResult2>0 && eqResult3*eqResult2<0)
    {
        xl = xr;
        return proses (xl,xu,xr,iterasi,flag1,flag2,starterxl,starterxu);
    }
    else if (eqResult1*eqResult2>0 && eqResult3*eqResult2>0)
    {
        float intOfint1, intOfint2;
        hasil((xl+xr)/2,intOfint1);
        hasil((xu+xr)/2,intOfint2);
        if (eqResult1<0 && eqResult3<0)
        {
            printf("Tidak ada akar persamaan");
        }
        else if (eqResult1<intOfint1 && intOfint1<eqResult2 && eqResult2<intOfint2 && intOfint2<eqResult3)
        {
            if (flag1 == 2)
            {
                printf("Tidak ada akar persamaan lain antara interval yang dimasukkan");
            }
            else
            {
                printf("Tidak ada akar persamaan");
            }
        }
        else if (eqResult1>intOfint1 && intOfint1>eqResult2 && eqResult2>intOfint2 && intOfint2>eqResult3)
        {
            if (flag1 == 2)
            {
                printf("Tidak ada akar persamaan lain antara interval yang dimasukkan");
            }
            else
            {
                printf("Tidak ada akar persamaan");
            }
        }
        else if (eqResult1<eqResult3)
        {
            xu = xr;
            return proses (xl,xu,xr,iterasi,flag1,flag2,starterxl,starterxu);
        }
        else if (eqResult1>eqResult3)
        {
            xl = xr;
            return proses (xl,xu,xr,iterasi,flag1,flag2,starterxl,starterxu);
        }
    }
    else if (eqResult1*eqResult2<0 && eqResult3*eqResult2>0)
    {
        xu = xr;
        return proses (xl,xu,xr,iterasi,flag1,flag2,starterxl,starterxu);
    }
    else if (eqResult1*eqResult2<0 && eqResult3*eqResult2<0)
    {
        if (flag1 == 3)
        {
            xl = xr;
            return proses (xl,xu,xr,iterasi,flag1,flag2,starterxl,starterxu);
        }
        else
        {
            flag2 = 1;
            xu = xr;
            return proses (xl,xu,xr,iterasi,flag1,flag2,starterxl,starterxu);
        }
    }
    else
    {
        if (flag1 == 1)
        {
            if (flag2 == 1)
            {
                printf("Salah satu akar persamaan antara interval yang dimasukkan adalah : %f\n", xr);
                printf("Ditemukan setelah iterasi ke %d\n", iterasi );
                printf("Lanjutkan untuk mencari akar persamaan lainnya\n\n");
                flag1 = 3;
                return proses (starterxl,starterxu,xr,iterasi,flag1,flag2,starterxl,starterxu);
            }
            else
            {
                printf("Akar persamaan antara interval yang dimasukkan adalah : %f\n", xr);
                printf("Ditemukan setelah iterasi ke %d\n", iterasi);
            }
        }
        else if (flag1 == 2 || flag1 == 3)
        {
            printf("Akar persamaan lain antara interval  yang dimasukkan adalah : %f\n", xr);
            printf("Ditemukan setelah iterasi ke %d\n ", iterasi);
        }
    }
}

int main()
{
    float xl, xu, xr, starterxl, starterxu;
    int iterasi = 0;
    int flag1 =  0, flag2 = 0;
    printf("Batas Bawah: ");
    scanf("%f", &xl);
    printf("Batas Atas: ");
    scanf("%f", &xu);
    starterxl = xl;
    starterxu = xu;
    proses(xl,xu,xr,iterasi,flag1,flag2,starterxl,starterxu);
    return 0;
}