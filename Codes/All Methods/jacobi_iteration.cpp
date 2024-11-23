#include "Common/linear_equations.hpp"

int main()
{
    char s[100];
    int row, column;
    double **arr;
    double *roots;
    double *temps;
    double *prev;
    int len, i, j;

    puts("Enter number of variables: ");
    scanf("%d ", &row);

    arr = create_arr(row, row + 1);
    roots = (double *) calloc(row, sizeof(double));
    temps = (double *) calloc(row, sizeof(double));
    prev = (double *) calloc(row, sizeof(double));

    column = row + 1;

    for (i = 0; i < row; i++) {
        fgets(s, 100, stdin);
        
        len = strlen(s);

        get_nums(s, column, arr[i], len);
    }

    for (i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            printf("%0.4lf ", arr[i][j]);
        }

        printf("\n");
    }

    for (int it = 0; it < 500; it++) {
        for (i = 0; i < row; i++) {
            temps[i] = 1.0 * arr[i][column - 1];

            for (j = 0; j < row; j++) {
                if (i != j) {
                    temps[i] -= 1.0 * arr[i][j] * roots[j];
                }
            }

            temps[i] /= (1.0 * arr[i][i]);
        }

        assign(roots, temps, row);

        if (equal(roots, prev, row)) {
            break;
        }
        else {
            assign(prev, roots, row);
        }

        printf("it: %d -- ", it);
        print_roots(roots, row);
    }

    printf("Roots: ");
    
    print_roots(roots, row);

    return 0;
}