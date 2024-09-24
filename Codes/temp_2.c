#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void get_nums(char *s, int count, int *arr, int len)
{
    int *sign = (int *) malloc(sizeof(int) * count);
    int i = 0, j = 0, k;

    for (k = 0; k < count; k++) {
        arr[k] = 0;
        sign[k] = 1;
    }

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

int main()
{
    char s[100];
    int row, column;
    int **arr;
    int len, i;

    puts("Enter number of variables: ");
    scanf("%d ", &row);

    arr = (int **) malloc(sizeof(int *) * row);

    column = row + 1;

    for (i = 0; i < row; i++) {
        arr[i] = (int *) malloc(sizeof(int) * column);
    }

    fgets(s, 100, stdin);

    len = strlen(s);

    get_nums(s, column, arr[0], len);
    
    for (int i = 0; i < column; i++) {
        printf("%d ", arr[0][i]);
    }

    return 0;
}