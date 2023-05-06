#include <stdio.h>
#include "math.h"

double fxy(double x, double y){
    return pow(x,3) * y;
}

double runge_kutt(double x0, double y0, double h, int m){
    double k1, k2, k3, k4;
    for (int i=0; i<m; i++){
        k1 = fxy(x0, y0);
        k2 = fxy(x0 + h/2, y0 + h*k1/2);
        k3 = fxy(x0 + h/2, y0 + h*k2/2);
        k4 = fxy(x0 + h, y0 + h*k3);
        y0 += (h/6)*(k1 + 2*k2 + 2*k3 + k4);
        x0 += h;
    }
    return y0;
}

void count(double x0, double y0, double h0, double acc, int n){
    double h, y, y1, x;
    int m = 0;
    printf("x = %.1lf, y = %.5lf, h = %.5lf, m = %d\n", x0, y0, h0, m);
    for(int i=0; i<n; i++){
        m = 1;
        h = h0;
        y = runge_kutt(x0, y0, h, m);
        do{
            y1 = y;
            h = h/2;
            x = x0;
            y = y0;
            m = 2*m;
            y = runge_kutt(x, y, h, m);
        } while(abs(y - y1) > acc);
        x0 = x0 + h0;
        y0 = y;
        printf("x = %.1lf, y = %.5lf, h = %.5lf, m = %d\n", x0, y0, h, m);
    }
}

int main(void){
    int a=0, b=2;
    double h0=0.2, acc, x0=0, y0=1;
    int n = (b-a)/h0;

    printf("Введите точность: ");
    scanf("%lf", &acc);
    
    count(x0, y0, h0, acc, n);
    return 0;
}