from Common.algebraic_expression_evaluator import infix_to_postfix as itp, evaluate_postfix as ep, derivative as ddx

f = itp(input())

x1, x2 = map(float, input().split())
x = None

while abs(x1 - x2) > 1e-6:
    f1 = ep(f, x1)
    f2 = ep(f, x2)
    
    x = x2 - (f2 * (x2 - x1)) / (f2 - f1)
    
    x1 = x2
    x2 = x
    
print(f"Root = {x:.6}")