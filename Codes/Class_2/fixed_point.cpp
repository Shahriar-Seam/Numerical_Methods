#include <bits/stdc++.h>

using namespace std;

double f(double x) {
    return x * x + x - 2;
}

double g(double x) {
    return 2 - x * x;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double x0 = 0, x1, prev_x1 = 0;
    int i;

    while (1) {
        x1 = g(x0);

        cout << "Iteration " << i++ << ": " << x1 << "\n";

        if (abs(x1 - prev_x1) < 1e-6) {
            break;
        }

        prev_x1 = x1;
        x0 = x1;
    }

    cout << "Root = " << x1 << "\n";

    return 0;
}