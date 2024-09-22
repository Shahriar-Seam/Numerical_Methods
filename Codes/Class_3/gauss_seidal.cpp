#include <bits/stdc++.h>

using namespace std;

int equal(double a, double b)
{
    return abs(a - b) < 0.000000001;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double x1 = 0, x2 = 0, x3 = 0;
    double prev_x1 = 0, prev_x2 = 0, prev_x3 = 0;
    double a1, b1, c1, d1, a2, b2, c2, d2, a3, b3, c3, d3;
    int i;

    cin >> a1 >> b1 >> c1 >> d1;
    cin >> a2 >> b2 >> c2 >> d2;
    cin >> a3 >> b3 >> c3 >> d3;

    for (i = 0; i < 200; i++) {
        x1 = (d1 - b1 * x2 - c1 * x3) / (a1);
        x2 = (d2 - a2 * x1 - c2 * x3) / (b2);
        x3 = (d3 - a3 * x1 - b3 * x2) / (c3);

        if (equal(x1, prev_x1) && equal(x2, prev_x2) && equal(x3, prev_x3)) {
            break;
        }
        else {
            prev_x1 = x1;
            prev_x2 = x2;
            prev_x3 = x3;
        }
    }

    cout << x1 << " " << x2 << " " << x3 << "\n";

    return 0;
}