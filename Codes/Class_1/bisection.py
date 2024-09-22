fn = input()

x1, x2 = map(float, input().split())
it = int(input())

while (it > 0 or abs(x2 - x1) < 0.0005):
    x = x0 = (x1 + x2) / 2
    f0 = eval(fn)
    x = x1
    f1 = eval(fn)
    x = x2
    f2 = eval(fn)
    
    if f0 == 0:
        break
    elif f0 * f1 < 0:
        x2 = x0
    elif f0 * f2 < 0:
        x1 = x0
    else:
        print(f"Root not in range {x1} and {x2}")
        break
    
print(f"Root = {x0}")