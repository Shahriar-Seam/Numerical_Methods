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

        sum_x += log(x);
        sum_y += log(y);
        sum_xy += log(x) * log(y);
        sum_x2 += pow(log(x), 2);
    }

    double b = (n * sum_xy - sum_x * sum_y) / (n * sum_x2 - (sum_x * sum_x));

    double ln_a = sum_y / n - b * sum_x / n;

    double a = exp(ln_a);

    printf("y = %gx^%g", a, b);

    return 0;
}