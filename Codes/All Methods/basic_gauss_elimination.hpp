#include "Common/linear_equations.hpp"

void basic_gauss_elimination(double **arr, double *roots, int row, int column)
{
    int i, j, k;

    // eq_1 - eq_j * a1 / a_j
    for (i = 0; i < row - 1; i++) {    
        double pivot = arr[i][i];

        for (j = i + 1; j < row; j++) {
            double temp = arr[j][i];

            for (k = i; k < column; k++) {
                arr[j][k] = arr[i][k] - (arr[j][k] * pivot) / temp;
            }
        }

        sort(&arr, row, column);

        print_arr(arr, row, column);

        int ready = is_ready(arr, row, column);

        if (ready == 1) {
            break;
        }
        else if (ready == -1) {
            printf("Can't Solve.\nBye Bye!!!\n");

            exit(0);
        }
    }

    for (i = 0; i < row; i++) {
        double pivot = arr[i][i];

        for (j = i; j < column; j++) {
            arr[i][j] /= pivot;
        }
    }

    for (i = row - 1; i >= 0; i--) {
        roots[i] = arr[i][column - 1];

        for (j = i + 1; j < row; j++) {
            roots[i] -= roots[j] * arr[i][j];
        }
    }

    print_arr(arr, row, column);
}
