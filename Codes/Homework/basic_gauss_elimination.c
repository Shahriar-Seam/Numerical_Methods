#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

void get_nums(char *s, int count, double *arr, int len);
void basic_gauss_elimination(double **arr, double *roots, int row, int column);
void print_arr(double **arr, int row, int column);

void get_nums(char *s, int count, double *arr, int len)
{
    int *sign = (int *) malloc(sizeof(int) * count);
    int i = 0, j = 0, k, is_dot = 0, dot = 0;

    // Initialize the arrays
    for (k = 0; k < count; k++) {
        arr[k] = 0;
        sign[k] = 1;
    }

    // Get the coefficients
    for (k = 0; k < count - 1; k++, j++) {
        is_dot = 0;
        dot = 0;

        if (s[i] == '-') {
            sign[j] = -1;

            i++;
        }

        if (k > 0) {
            i++;
        }

        while (s[i] == ' ') {
            i++;
        }

        if (s[i] == 'x') {
            arr[j] = 1;
            i++;
        }
        else {
            while (isdigit(s[i]) || s[i] == '.') {
                if (s[i] == '.') {
                    i++;
                    is_dot = 1;

                    continue;
                }

                if (is_dot) {
                    dot++;
                }

                arr[j] *= 10;
                arr[j] += s[i] - '0';
                i++;
            }

            arr[j] /= pow(10, dot);
        }

        while (i < len && (s[i] != '+' && s[i] != '-' && s[i] != '=')) {
            i++;
        }
    }

    // Constant
    while (s[i] == '=' || s[i] == ' ') {
        i++;
    }

    if (s[i] == '-') {
        sign[j] = -1;

        i++;
    }

    while (i < len && (!isdigit(s[i]) && s[i] != 'x')) {
        i++;
    }

    if (i < len && s[i] == 'x') {
        arr[j] = 1;

        i++;
    }
    else {
        while (i < len && isdigit(s[i])) {
            arr[j] *= 10;
            arr[j] += s[i] - '0';
            i++;
        }
    }

    for (j = 0; j < count; j++) {
        arr[j] *= sign[j];
    }

    free(sign);
}

void basic_gauss_elimination(double **arr, double *roots, int row, int column)
{
    int i, j, k;

    // eq_1 - eq_j * a1 / a_j
    for (i = 0; i < row; i++) {    
        double pivot = arr[i][i];

        for (j = i + 1; j < row; j++) {
            double temp = arr[j][i];

            for (k = i; k < column; k++) {
                arr[j][k] = arr[i][k] - (arr[j][k] * pivot) / temp;
            }
        }

        print_arr(arr, row, column);
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
}

void print_arr(double **arr, int row, int column)
{
    int i, j;

    printf("arr:\n");
    for (i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            printf("%g ", arr[i][j]);
        }

        printf("\n");
    }

    printf("\n");
}

void print_roots(double *roots, int count)
{
    int i;

    for (i = 0; i < count; i++) {
        printf("%0.4lf ", roots[i]);
    }

    printf("\n");
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

    basic_gauss_elimination(arr, roots, row, column);

    print_arr(arr, row, column);

    print_roots(roots, row);

    return 0;
}