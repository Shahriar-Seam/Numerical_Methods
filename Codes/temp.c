#include <stdio.h>
#include <string.h>
#include <ctype.h>

void get_nums(char *s, int *A, int *B, int *C, int *D)
{
    int s_a = 1, s_b = 1, s_c = 1, s_d = 1;
    int a = 0, b = 0, c = 0, d = 0;
    int i = 0;
    int len = strlen(s);

    // a
    if (s[0] == '-') {
        s_a = -1;
        i++;
    }

    while (i < len && s[i] == ' ') {
        i++;
    }

    if (i < len && s[i] == 'x') {
        a = 1;
        i++;
    }
    else {
        while (i < len && isdigit(s[i])) {
            a *= 10;
            a += s[i] - '0';
            i++;
        }
    }

    while (i < len && (s[i] != '+' && s[i] != '-')) {
        i++;
    }

    // b
    if (i < len && s[i] == '-') {
        s_b = -1;
    }

    i++;

    while (i < len && (!isdigit(s[i]) && s[i] != 'x')) {
        i++;
    }

    if (i < len && s[i] == 'x') {
        b = 1;

        i++;
    }
    else {
        while (i < len && isdigit(s[i])) {
            b *= 10;
            b += s[i] - '0';
            i++;
        }
    }

    while (i < len && (s[i] != '+' && s[i] != '-')) {
        i++;
    }

    // c
    if (i < len && s[i] == '-') {
        s_c = -1;
    }

    i++;

    while (i < len && (!isdigit(s[i]) && s[i] != 'x')) {
        i++;
    }

    if (i < len && s[i] == 'x') {
        c = 1;

        i++;
    }
    else {
        while (i < len && isdigit(s[i])) {
            c *= 10;
            c += s[i] - '0';
            i++;
        }
    }

    while (i < len && (s[i] != '+' && s[i] != '-')) {
        i++;
    }

    // d
    if (i < len && s[i] == '-') {
        s_d = -1;
    }

    i++;

    while (i < len && (!isdigit(s[i]) && s[i] != 'x')) {
        i++;
    }

    if (i < len && s[i] == 'x') {
        d = 1;

        i++;
    }
    else {
        while (i < len && isdigit(s[i])) {
            d *= 10;
            d += s[i] - '0';
            i++;
        }
    }

    *A = (s_a * a);
    *B = (s_b * b);
    *C = (s_c * c);
    *D = (s_d * d);
}

int main()
{
    char s[50];
    int a, b, c, d;

    gets(s);

    get_nums(s, &a, &b, &c, &d);

    printf("%d %d %d %d\n", a, b, c, d);

    return 0;
}