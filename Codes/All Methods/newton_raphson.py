from Common.algebraic_expression_evaluator import infix_to_postfix as itp, evaluate_postfix as ep, derivative as ddx

f = itp(input())

x = None
x_prev = float(input())

for _ in range(500):
    x = x_prev - ep(f, x_prev) / ddx(f, x_prev)
    
    if x == x_prev:
        break
    
    x_prev = x
    
print(f"Root = {x:.6}")