#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

void get_nums(char *s, int count, double *arr, int len);
void basic_gauss_elimination(double **arr, double *roots, int row, int column);
void print_arr(double **arr, int row, int column);
void print_roots(double *roots, int count);
void sort(double ***arr, int row, int column);
int is_ready(double **arr, int row, int column);
int compare(const void *a, const void *b);

typedef struct item {
    int var_count;
    int index;
} item;

int compare(const void *a, const void *b) {
    item *A = (item *) a;
    item *B = (item *) b;

    if (B->var_count > A->var_count) {
        return 1;
    }
    else if (B->var_count == A->var_count) {
        if (B->index < A->index) {
            return 1;
        }
        else {
            return -1;
        }
    }
    else {
        return -1;
    }
}

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

void sort(double ***arr, int row, int column)
{
    int i, j, var_count, is_ordered = 1;
    double **temp = (double **) malloc(sizeof(double *) * row);
    
    struct item *counter = (struct item *) calloc(row, sizeof(struct item));

    for (i = 0; i < row; i++) {
        temp[i] = (double *) malloc(sizeof(double) * column);
    }

    for (i = 0; i < row; i++) {
        var_count = 0;

        for (j = 0; j < column - 1; j++) {
            var_count += ((*arr)[i][j] != 0);
        }

        counter[i].var_count = var_count;
        counter[i].index = i;
    }

    for (i = 1; i < row; i++) {
        if (counter[i].var_count < counter[i - 1].var_count) {
            is_ordered = 0;

            break;
        }
    }

    if (is_ordered) {
        return;
    }

    qsort(counter, row, sizeof(struct item), compare);

    for (i = 0; i < row; i++) {
        for (j = 0; j < column; j++) {
            temp[i][j] = (*arr)[counter[i].index][j];
        }
    }

    *arr = temp;
}

int is_ready(double **arr, int row, int column)
{
    int i, j, var_count, ready = 1;
    
    struct item *counter = (struct item *) calloc(row, sizeof(struct item));

    for (i = 0; i < row; i++) {
        var_count = 0;

        for (j = 0; j < column - 1; j++) {
            var_count += arr[i][j] != 0;
        }

        counter[i].var_count = var_count;
        counter[i].index = i;
    }

    for (i = 0; i < row; i++) {
        if (counter[i].var_count != row - i) {
            ready = 0;
        }
        if (counter[i].var_count < row - i) {
            ready = -1;

            break;
        }
    }

    return ready;
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

    print_roots(roots, row);

    return 0;
}