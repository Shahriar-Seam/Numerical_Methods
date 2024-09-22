#include <bits/stdc++.h>

using namespace std;

double f(double x)
{
    return x * x - x - 2;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << setprecision(20);

    double x1, x2, x0;
    double f1, f2, f0;
    int it;

    cout << "Enter x1 and x2:\n";
    cin >> x1 >> x2;

    cout << "Enter number of iterations:\n";
    cin >> it;

    while (it-- || abs(x2 - x1) <= 0.0005) {
        f1 = f(x1);
        f2 = f(x2);

        x0 = x1 - (f1 * (x2 - x1)) / (f2 - f1);

        cout << x0 << "\n";

        f0 = f(x0);

        if (f0 == 0) {
            cout << "found\n";

            break;
        }
        else if (f0 * f1 < 0) {
            x2 = x0;
        }
        else if (f0 * f2 < 0) {
            x1 = x0;
        }
        else {
            printf("Not inside the range %0.4lf and %0.4lf.\n", x1, x2);

            break;
        }
    }

    cout << "Root = " << x0 << "\n";

    return 0;
}