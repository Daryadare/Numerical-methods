#include <stdio.h>
#include "math.h"

double formula(double x){
    return cos(x/5) * pow((1+x), 0.5) - x;
}

double derivative(double x){
    return (2*sqrt(1+x) * (5 + sin(x/5) * sqrt(1+x)) - 5*cos(x/5)) / -10 * sqrt(1+x);
}

double recursive(double x, double f, double f1){
    return x - f/f1;
}

int main(void){
    double accuracy, x, fx, fdx, f2;
    int n = 0;

    printf("Введите точность: ");
    scanf("%lf", &accuracy);
    printf("Введите x: ");
    scanf("%lf", &x);

    do{
        fx = formula(x);
        fdx = derivative(x);
        printf("Итерация %d: x = %f f(x) = %8f\n", n, x, fx);
        x = recursive(x, fx, fdx);
        f2 = formula(x);
        n += 1;
    } while(abs(f2) > accuracy);
    
    printf("Точность превышена");
    return 0;
}
