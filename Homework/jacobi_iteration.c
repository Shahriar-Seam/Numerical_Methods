#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

void get_nums(char *s, int count, int *arr, int len)
{
    int *sign = (int *) malloc(sizeof(int) * count);
    int i = 0, j = 0, k;

    // Initialize the arrays
    for (k = 0; k < count; k++) {
        arr[k] = 0;
        sign[k] = 1;
    }

    // Get the coefficients
    for (k = 0; k < count - 1; k++, j++) {
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
            while (isdigit(s[i])) {
                arr[j] *= 10;
                arr[j] += s[i] - '0';
                i++;
            }
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

// abs supports int only
double diff(double a, double b)
{
    return a > b ? a - b : b - a;
}

bool equal(double *roots, double *prev, int count)
{
    int i;

    for (i = 0; i < count; i++) {
        if (diff(roots[i], prev[i]) > 1e-9) {
            return false;
        }
    }

    return true;
}

void assign(double *arr1, double *arr2, int count)
{
    int i;

    for (i = 0; i < count; i++) {
        arr1[i] = arr2[i];
    }
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
    int **arr;
    double *roots;
    double *temps;
    double *prev;
    int len, i, j;

    puts("Enter number of variables: ");
    scanf("%d ", &row);

    arr = (int **) malloc(sizeof(int *) * row);
    roots = (double *) calloc(row, sizeof(double));
    temps = (double *) calloc(row, sizeof(double));
    prev = (double *) calloc(row, sizeof(double));

    column = row + 1;

    for (i = 0; i < row; i++) {
        arr[i] = (int *) malloc(sizeof(int) * column);
    }


    for (i = 0; i < row; i++) {
        fgets(s, 100, stdin);
        
        len = strlen(s);

        get_nums(s, column, arr[i], len);
    }

    for (i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            printf("%d ", arr[i][j]);
        }

        printf("\n");
    }

    for (int it = 0; ; it++) {
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