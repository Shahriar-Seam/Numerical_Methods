#include <stdio.h>

double f(double x, double y)
{
    return 3 * x * x + 1;
}

int main()
{
    double x, y, h, stop;

    x = 1;
    y = 2;
    h = 0.25;
    stop = 2;

    scanf("%lf %lf %lf %lf", &x, &y, &h, &stop);

    printf("x = %g, y = %g\n", x, y);

    while (x < stop) {
        y = y + h * f(x, y);

        x += h;

        printf("x = %g, y = %g\n", x, y);
    }

    return 0;
}