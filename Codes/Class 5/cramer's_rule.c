// For 3x3 matrix only

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

void get_nums(char *s, int count, int *arr, int len)
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

        if (k > 0 && !isdigit(s[i])) {
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

void print_arr(int **arr, int row, int column)
{
    int i, j;

    printf("arr:\n");
    for (i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            printf("%d ", arr[i][j]);
        }

        printf("\n");
    }

    printf("\n");
}

void print_roots(int *roots, int count)
{
    int i;

    printf("Roots: ");
    for (i = 0; i < count; i++) {
        printf("%d ", roots[i]);
    }

    printf("\n");
}

int determinant(int **arr, int row, int column, int col_num)
{
    int i, j;
    int **temp;

    temp = (int **) malloc(sizeof(int *) * row);

    for (i = 0; i < row; i++) {
        temp[i] = (int *) malloc(sizeof(int) * (column - 1));
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
    int **arr;
    int *roots;
    int len, i, j;

    puts("Enter number of variables: ");
    scanf("%d ", &row);

    arr = (int **) malloc(sizeof(int *) * row);
    roots = (int *) calloc(row, sizeof(int));

    column = row + 1;

    for (i = 0; i < row; i++) {
        arr[i] = (int *) malloc(sizeof(int) * column);
    }


    for (i = 0; i < row; i++) {
        fgets(s, 100, stdin);
        
        len = strlen(s);

        get_nums(s, column, arr[i], len);
    }

    print_arr(arr, row, column);

    int D, d[row];

    D = determinant(arr, row, column, -1);
    d[0] = determinant(arr, row, column, 0);
    d[1] = determinant(arr, row, column, 1);
    d[2] = determinant(arr, row, column, 2);

    printf("%d %d %d %d\n", D, d[0], d[1], d[2]);

    for (i = 0; i < row; i++) {
        roots[i] = d[i] / D;
    }

    print_roots(roots, row);

    return 0;
}