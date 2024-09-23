#include <bits/stdc++.h>

using namespace std;

double f(double x) {
    return x * x - 3 * x + 2;
}

double diff(double x) {
    return 2 * x - 3;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double x1 = 0, x2 = 0, prev_x2 = 0;
    int i = 1;

    while (1) {
        x2 = x1 - f(x1) / diff(x1);

        cout << "Iteration " << i++ << ": " << x2 << "\n";

        if (abs(x2 - prev_x2) < 1e-6) {
            break;
        }

        prev_x2 = x2;
        x1 = x2;
    }

    cout << "Root = " << x2 << "\n";

    return 0;
}