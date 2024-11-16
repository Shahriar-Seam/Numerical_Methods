from algebraic_expression_evaluator import infix_to_postfix as itp, evaluate_postfix as ep, derivative as ddx

f = itp(input())

x = 1
y = 2
h = 0.25
stop = 2

while x < stop:
    y = y + h * ep(f, x, y)
    
    x += h
    
print(y)