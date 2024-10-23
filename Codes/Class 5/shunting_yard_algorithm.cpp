#include <bits/stdc++.h>

using namespace std;

#define NONE -1
#define T_NUMBER 0
#define T_OPERATOR 1
#define T_VARIABLE 2
// #define T_FUNCTION 3
// #define T_BRACKET 4

#define PLUS 101
#define MINUS 101
#define MULTIPLY 102
#define DIVIDE 103
#define POWER 104

#define X 201
#define Y 202

typedef struct {
    int type;
    int value;
} token;

string VARIABLES = "xy";

int preceding(char c1, char c2)

token next_token()
{
    char c;
    token t;

    do {
        c = getchar();
    } while (c == ' ');

    if (isdigit(c)) {
        t.type = T_NUMBER;
        t.value = 0;

        do {
            t.value = t.value * 10 + c - '0';
            c = getchar();
        } while (isdigit(c));
        ungetc(c, stdin);
    }
    else if (isalpha(c)) {
        t.type = T_VARIABLE;
        t.value = (c == 'x' ? X : Y);

        // Try to implement functions here
    }
    else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
        t.type = T_OPERATOR;
        t.value = c;
    }
    else {
        t.type = NONE;
    }

    return t;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    token t;
    queue <int> output;
    stack <char> operators;

    t = next_token();

    while (t.type != NONE) {
        switch (t.type)
        {
        case T_NUMBER:
            printf("%d\n", t.value);

            output.push(t.value);
            break;
        case T_OPERATOR:
            printf("%c\n", t.value);
            while (!operators.empty() && (operators.top() >= ))
            break;
        case T_VARIABLE:
            printf("%c\n", t.value);
            break;

        default:
            break;
        }

        t = next_token();
    }

    return 0;
}