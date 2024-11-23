#include "Common/linear_equations.hpp"

void gauss_jordan_elimination(double **arr, double *roots, int row, int column)
{
    int i, j, k;

    for (i = 0; i < row; i++) {
        double pivot = arr[i][i];

        if (pivot == 0) {
            printf("Won't solve.\nBye Bye!!!\n");

            exit(0);
        }

        for (j = 0; j < row; j++) {
            if (j != i) {
                double divisor = arr[j][i];
                for (k = 0; k < column; k++) {
                    arr[j][k] = arr[i][k] - arr[j][k] * pivot / divisor;
                }
            }
        }

        print_arr(arr, row, column);
    }

    for (i = 0; i < row; i++) {
        double pivot = arr[i][i];

        for (j = 0; j < column; j++) {
            arr[i][j] /= pivot;
        }

        roots[i] = arr[i][column - 1];
    }

    print_arr(arr, row, column);
}