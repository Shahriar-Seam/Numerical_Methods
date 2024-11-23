from Common.algebraic_expression_evaluator import infix_to_postfix as itp, evaluate_postfix as ep, derivative as ddx

f = itp(input())

start, stop = map(float, input().split())
h = float(input())

x = []
y = []

while start <= stop:
    x.append(start)
    
    start += h
    
y = [ep(f, x = i) for i in x]

trapezoidal = h / 2 * sum([y[i] if i == 0 or i == len(y) - 1 else 2 * y[i] for i in range(len(y))])

simpson_1_3 = h / 3 * sum([y[i] if i == 0 or i == len(y) - 1 else 4 * y[i] if i % 2 == 1 else 2 * y[i] for i in range(len(y))])

simpson_3_8 = 3 * h / 8 * sum([y[i] if i == 0 or i == len(y) - 1 else 2 * y[i] if i % 3 == 0 else 3 * y[i] for i in range(len(y))])

print(f"I = {trapezoidal:.5}")
print(f"I = {simpson_1_3:.5}")
print(f"I = {simpson_3_8:.5}")