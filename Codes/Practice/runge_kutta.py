from algebraic_expression_evaluator import infix_to_postfix as itp, evaluate_postfix as ep, derivative as ddx

f = itp(input())

x = 0
stop = 0.4
h = 0.2
y = 0

while x < stop:
    m1 = ep(f, x, y)
    m2 = ep(f, x + h / 2, y + m1 * h / 2)
    m3 = ep(f, x + h / 2, y + m2 * h / 2)
    m4 = ep(f, x + h, y + m3 * h)
    
    y = y + h / 6 * (m1 + 2 * m2 + 2 * m3 + m4)
    x += h
    
print(f"y({x}) = {y}")