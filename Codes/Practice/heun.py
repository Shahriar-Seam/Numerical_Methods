from algebraic_expression_evaluator import infix_to_postfix as itp, evaluate_postfix as ep, derivative as ddx

f = itp(input())

x = 1
stop = 2
h = 0.25
y = 2
y_n = None

while x < stop:
    m1 = ep(f, x, y)
    y_n = y + h * m1
    x += h
    
    m2 = ep(f, x, y_n)
    y_n = y + h / 2 * (m1 + m2)
    y = y_n
    
print(f"y({x}) = {y:.6}")