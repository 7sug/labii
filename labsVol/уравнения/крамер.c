#include <math.h>
#include <stdio.h>
 
int Kramer(float a11,float a12,
            float a21,float a22,
            float b1 ,float b2,
            float *x ,float *y)
{
    float det,detx,dety;
    det =a11*a22-a12*a21;
    detx=b1*a22-b2*a12;
    dety=a11*b2-b1*a21;
 
    if (fabs(det) > 1.0E-14) 
    {
        *x=detx/det;
        *y=dety/det;
        return 0; 
    }
    else
        if ((fabs(detx) <1.0E-14) && (fabs(dety) <1.0E-14))
            return 1; 
        else
            return -1; 
}
 
int main(int argc, char* argv[])
{
    float A11,A12,B1,A21,A22,B2,X,Y;
    int rc;
 
    printf("A11=");
    scanf("%e",&A11);
    printf("A12=");
    scanf("%e",&A12);
    printf("B1=");
    scanf("%e",&B1);
 
    printf("A21=");
    scanf("%e",&A21);
    printf("A22=");
    scanf("%e",&A22);
    printf("B2=");
    scanf("%e",&B2);
 
    rc=Kramer(A11,A12,A21,A22,B1,B2,&X,&Y);
 
    if (rc == 0)
        printf("X=%e\nY=%e\n",X,Y);
    else
        if (rc == 1)
            printf("Infinite set of roots...\n");
        else
            printf("Set of roots is empty...\n");
 
    return 0;
}