// #include "basic_gauss_elimination.hpp"
#include "gauss_jordan.hpp"
// #include "gauss_seidal.hpp"

int main()
{
    char s[100];
    int row, column;
    double **arr;
    double *roots;
    int len, i, j;

    puts("Enter number of variables: ");
    scanf("%d ", &row);

    arr = create_arr(row, row + 1);
    roots = (double *) calloc(row, sizeof(double));

    column = row + 1;

    for (i = 0; i < row; i++) {
        fgets(s, 100, stdin);
        
        len = strlen(s);

        get_nums(s, column, arr[i], len);
    }

    print_arr(arr, row, column);

    gauss_jordan_elimination(arr, roots, row, column);
    // gauss_seidal(arr, roots, row, column);
    // basic_gauss_elimination(arr, roots, row, column);

    cout << "Roots: ";
    print_roots(roots, row);

    return 0;
}