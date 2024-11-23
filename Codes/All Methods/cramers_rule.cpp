// For 3x3 matrix only
#include "Common/linear_equations.hpp"

double determinant(double **arr, int row, int column, int col_num)
{
    int i, j;
    double **temp;

    temp = (double **) malloc(sizeof(double *) * row);

    for (i = 0; i < row; i++) {
        temp[i] = (double *) malloc(sizeof(double) * (column - 1));
    }

    for (i = 0; i < row; i++) {
        for (j = 0; j < column - 1; j++) {
            temp[i][j] = arr[i][j];
        }
    }

    if (col_num != -1) {
        for (i = 0; i < row; i++) {
            temp[i][col_num] = arr[i][column - 1];
        }
    }

    int d = 0;
    
    for (i = 0; i < row; i++) {
        d += temp[i][0] * (temp[(i + 1) % 3][1] * temp[(i + 2) % 3][2] - temp[(i + 1) % 3][2] * temp[(i + 2) % 3][1]);
    }

    print_arr(temp, row, column - 1);

    return d;
}

int main()
{
    char s[100];
    int row, column;
    double **arr;
    double *roots;
    int len, i, j;

    puts("Enter number of variables: ");
    scanf("%d ", &row);

    arr = (double **) malloc(sizeof(double *) * row);
    roots = (double *) calloc(row, sizeof(double));

    column = row + 1;

    for (i = 0; i < row; i++) {
        arr[i] = (double *) malloc(sizeof(double) * column);
    }

    for (i = 0; i < row; i++) {
        fgets(s, 100, stdin);
        
        len = strlen(s);

        get_nums(s, column, arr[i], len);
    }

    print_arr(arr, row, column);

    double D, d[row];

    D = determinant(arr, row, column, -1);
    d[0] = determinant(arr, row, column, 0);
    d[1] = determinant(arr, row, column, 1);
    d[2] = determinant(arr, row, column, 2);

    printf("%lf %lf %lf %lf\n\n", D, d[0], d[1], d[2]);

    for (i = 0; i < row; i++) {
        roots[i] = d[i] / D;
    }

    cout << "Roots: ";
    print_roots(roots, row);

    return 0;
}