#include <bits/stdc++.h>

using namespace std;

double f(double x) {
    return x * x - 4 * x - 10;
}

double x_next(double x, double x_prev) {
    return x - (f(x) * (x - x_prev)) / (f(x) - f(x_prev));
}

int main()
{
    cout << fixed << setprecision(5);

    double x1 = 4, x2 = 2, x3;
    double prev_x1 = x1, prev_x2 = x2;
    int i = 1;

    while (1) {
        x3 = x_next(x2, x1);

        x1 = x2;
        x2 = x3;
        
        cout << "Iteration " << i << ": " << x3 << "\n";
        i++;

        if (abs(prev_x1 - x1) < 1e-6 && abs(prev_x2 - x2) < 1e-6) {
            break;
        }

        prev_x1 = x1;
        prev_x2 = x2;
    }


    return 0;
}