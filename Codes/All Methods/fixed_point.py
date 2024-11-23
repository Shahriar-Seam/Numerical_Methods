from Common.algebraic_expression_evaluator import infix_to_postfix as itp, evaluate_postfix as ep, derivative as ddx

f = itp('(' + input() + ')' + '+x')

x = 1
x_prev = 0.0

while abs(x - x_prev) > 1e-6:
    x = ep(f, x_prev)
    
    x_prev = x
    
print(f"Root = {x:.6}")