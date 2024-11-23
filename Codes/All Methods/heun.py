from Common.algebraic_expression_evaluator import infix_to_postfix as itp, evaluate_postfix as ep, derivative as ddx
import re

f = itp(input())

match = re.match(r'y\(([\d\.]+)\)\s*=\s*([\d\.]+)', input())
x, y = float(match.group(1)), float(match.group(2))

h = float(input().split('=')[1])
stop = float(input().split('=')[1])
y_n = None

while x < stop:
    m1 = ep(f, x, y)
    y_n = y + h * m1
    x += h
    
    m2 = ep(f, x, y_n)
    y_n = y + h / 2 * (m1 + m2)
    y = y_n
    
print(f"y({x}) = {y:.6}")