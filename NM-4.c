#include <stdio.h>
#include "math.h"

double main_func(double x){
    return 0.25 * pow(x, 3) + cos(x/4);
}

double mean_rect(int a, int b, double n){
    double h = (b-a)/n;
    double res = 0, x;
    for (int i=0; i<n-1; i++){
        x = a + h/2 + i*h;
        res += main_func(x);
    }
    res *= h;
    return res;
}

double error_rate(double I, double I2, int p){
    return (I2-I)/p;
}

int main(void){
    int a = 1, b = 3, n = 4, p = 1;
    double acc, I, I2, R, Ires;

    printf("Введите точность: ");
    scanf("%lf", &acc);
    do{
        I = mean_rect(a, b, n);
        n *= 2;
        I2 = mean_rect(a, b, n);
        R = error_rate(I, I2, p);
    } while(abs(R) > acc);
    Ires = I2 + R;
    printf("Значение интеграла = %.8lf\n", Ires);
    printf("Значение погрешности = %lf\n", R);
    printf("Количество разбиений отрезка = %d", n);
    return 0;
}