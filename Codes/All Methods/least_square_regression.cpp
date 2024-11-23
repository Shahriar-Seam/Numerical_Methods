#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    double x, y;
    double sum_x, sum_y, sum_xy, sum_x2;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x >> y;

        sum_x += x;
        sum_y += y;
        sum_xy += x * y;
        sum_x2 += x * x;
    }

    double b = (n * sum_xy - sum_x * sum_y) / (n * sum_x2 - (sum_x * sum_x));

    double a = sum_y / n - b * sum_x / n;

    cout << "y = " << a << " + " << b << "x";

    return 0;
}