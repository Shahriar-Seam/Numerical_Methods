// For 3 variables only

#include "Common/linear_equations.hpp"

void gauss_seidal(double **arr, double *roots, int row, int column)
{
    int i;
    double x1 = 0, x2 = 0, x3 = 0;
    double prev_x1 = 0, prev_x2 = 0, prev_x3 = 0;
    double a1, b1, c1, d1, a2, b2, c2, d2, a3, b3, c3, d3;

    a1 = arr[0][0];
    a2 = arr[1][0];
    a3 = arr[2][0];
    
    b1 = arr[0][1];
    b2 = arr[1][1];
    b3 = arr[2][1];

    c1 = arr[0][2];
    c2 = arr[1][2];
    c3 = arr[2][2];

    d1 = arr[0][3];
    d2 = arr[1][3];
    d3 = arr[2][3];

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

    roots[0] = x1;
    roots[1] = x2;
    roots[2] = x3;
}
