import math

func = input("Enter the function: ")

def f(x):
    return eval(func)

def x_next(x, x_prev):
    return x - (f(x) * (x - x_prev)) / (f(x) - f(x_prev))

x1, x2 = map(float, input("Enter x1 and x2: ").split())

prev_x1 = x1
prev_x2 = x2
x3 = 0

i = 1

while True:
    x3 = x_next(x2, x1)

    x1 = x2
    x2 = x3
    
    print(f"Iteration {i} : {x3}")
    i += 1

    if abs(prev_x1 - x1) < 1e-6 and abs(prev_x2 - x2) < 1e-6:
        break

    prev_x1 = x1
    prev_x2 = x2

print(f"Root : {x3}")