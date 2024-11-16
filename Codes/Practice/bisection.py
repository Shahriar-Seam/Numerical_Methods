from algebraic_expression_evaluator import infix_to_postfix as itp, evaluate_postfix as ep

f = input()

f = itp(f)

print(' '.join(str(i) for i in f))

x1 = -2
x2 = -1
x0 = None

while abs(x1 - x2) > 1e-6:
    x0 = (x1 + x2) / 2
    
    f1 = ep(f, x1)
    f2 = ep(f, x2)
    f0 = ep(f, x0)
    
    if f0 == 0:
        break
    elif f0 * f1 < 0:
        x2 = x0
    elif f0 * f2 < 0:
        x1 = x0
    else:
        print(f"The root isn't inside {x1}, {x2}")
        break
    
print(f"Root = {x0:.6}")