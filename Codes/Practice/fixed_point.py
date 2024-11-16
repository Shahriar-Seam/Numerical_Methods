from algebraic_expression_evaluator import infix_to_postfix as itp, evaluate_postfix as ep, derivative as ddx

f = itp(input())

x = None
x_prev = 0

for _ in range(500):
    x = ep(f, x_prev)
    
    x_prev = x
    
print(f"Root = {x}")