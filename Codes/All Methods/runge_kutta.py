from Common.algebraic_expression_evaluator import infix_to_postfix as itp, evaluate_postfix as ep, derivative as ddx
import re

f = itp(input())

match = re.match(r'y\(([\d\.]+)\)\s*=\s*([\d\.]+)', input())
x, y = float(match.group(1)), float(match.group(2))

h = float(input().split('=')[1])
stop = float(input().split('=')[1])

while x < stop:
    m1 = ep(f, x, y)
    m2 = ep(f, x + h / 2, y + m1 * h / 2)
    m3 = ep(f, x + h / 2, y + m2 * h / 2)
    m4 = ep(f, x + h, y + m3 * h)
    
    y = y + h / 6 * (m1 + 2 * m2 + 2 * m3 + m4)
    x += h
    
print(f"y({x}) = {y:.5}")