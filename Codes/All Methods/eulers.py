from Common.algebraic_expression_evaluator import infix_to_postfix as itp, evaluate_postfix as ep, derivative as ddx
import re

f = itp(input())

match = re.match(r'y\(([\d\.]+)\)\s*=\s*([\d\.]+)', input())
x, y = float(match.group(1)), float(match.group(2))

h = float(input().split('=')[1])
stop = float(input().split('=')[1])

while x < stop:
    y = y + h * ep(f, x, y)
    
    x += h
    
print(f"y({stop}) = {y}")