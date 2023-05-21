#include <stdio.h>
#include "math.h"

double func(double x){
    return x * sin(x+1) - cos(x-5);
}

double golden_section(double a, double b, double acc){
    int n = 0;
    double k1 = (3-sqrt(5)) / 2, k2 = (sqrt(5)-1) / 2;
    double x1 = a + k1 * (b-a), x2 = a + k2 * (b-a);
    double xmin, F1 = func(x1), F2 = func(x2);

    printf("n=%d a=%.5f b=%.5f x1=%.5f x2=%.5f", n, a, b, x1, x2);
    printf(" f(x1)=%.5f f(x2)=%.5f (b-a)=%.5f\n", func(x1), func(x2), (b-a));
    do{
        if (F1 > F2){
            a = x1;
            x1 = x2;
            x2 = a + k2 * (b-a);
            F1 = F2;
            F2 = func(x2);
        }
        else{
            b = x2;
            x2 = x1;
            x1 = a + k1 * (b-a);
            F2 = F1;
            F1 = func(x1);
        }
        n += 1;
        printf("n=%d a=%.5f b=%.5f x1=%.5f x2=%.5f", n, a, b, x1, x2);
        printf(" f(x1)=%.5f f(x2)=%.5f (b-a)=%.5f\n", func(x1), func(x2), (b-a));
    } while ((b-a) > acc);

    xmin = (a + b) / 2;
    return xmin;
}

int main(){
    double a = 3.4, b = 4.4, acc = 0.0001;
    double xmin = golden_section(a, b, acc);
    printf("f(xmin)=%.7f xmin=%.7f", func(xmin), xmin);
    return 0;
}