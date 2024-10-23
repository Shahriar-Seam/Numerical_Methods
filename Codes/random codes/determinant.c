#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j;
    double **arr;

    scanf("%d", &n);

    *arr = (double **) malloc(sizeof(double *) * n);

    for (i = 0; i < n; i++) {
        arr[i] = (double *) malloc(sizeof(double) * n);
    }

    return 0;
}