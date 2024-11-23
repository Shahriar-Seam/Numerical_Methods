#include "basic_gauss_elimination.hpp"

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i;
    double x, y;
    double sum_x = 0, sum_x2 = 0, sum_x3 = 0, sum_x4 = 0;
    double sum_y = 0, sum_yx = 0, sum_yx2 = 0;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x >> y;

        sum_x  += x;
        sum_x2 += x * x;
        sum_x3 += x * x * x;
        sum_x4 += x * x * x * x;

        sum_y   += y;
        sum_yx  += y * x;
        sum_yx2 += y * x * x;
    }

    double **arr = create_arr(3, 4);
    double *roots = (double *) malloc(sizeof(double) * 3);

    arr[0][0] = n;
    arr[0][1] = arr[1][0] = sum_x;
    arr[0][2] = arr[1][1] = arr[2][0] = sum_x2;
    arr[1][2] = arr[2][1] = sum_x3;
    arr[2][2] = sum_x4;

    arr[0][3] = sum_y;
    arr[1][3] = sum_yx;
    arr[2][3] = sum_yx2;

    basic_gauss_elimination(arr, roots, 3, 4);

    cout << "y = " << roots[0] << " + " << roots[1] << "x + " << roots[2] << "x^2" << "\n";

    return 0;
}