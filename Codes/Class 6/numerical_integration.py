def clean(f):
    f_new = ""
    
    for i in range(len(f)):
        if f[i] == '^':
            f_new += "**"
        elif i > 0 and (f[i] == 'x' or f[i] == 'y'):
            if len(f_new) > 0 and f_new[-1] not in '+-*/ ':
                f_new += "*"
            f_new += f[i]
        else:
            f_new += f[i]
    
    return f_new

def make_table(f, l, r, h):
    x_vals = []
    y_vals = []
    
    while True:
        if l <= r:
            x_vals.append(l)
            l += h
        else:
            break
    
    for x in x_vals:
        y_vals.append(eval(f))
    
    print(x_vals)
    print(y_vals)
    
    return y_vals

def trapezoidal(y_vals, h):
    return h / 2 * sum([y if y_vals[0] == y or y_vals[-1] == y else 2 * y for y in y_vals])
    
def simpson_3_8(y_vals, h):
    return (3 * h / 8) * sum([y if y_vals[0] == y or y_vals[-1] == y else 2 * y if (y_vals.index(y) % 3 == 0) else 3 * y for y in y_vals])

def simpson_1_3(y_vals, h):
    return (h / 3) * sum([y if y_vals[0] == y or y_vals[-1] == y else 4 * y if (y_vals.index(y) % 2 == 1) else 2 * y for y in y_vals])

f = input("Enter expression:\n").split('=')[1]
l, r = map(float, input().split())
h = float(input("Enter h:\n").split('=')[1])

f = clean(f)

print(f"f = {f}")
y_vals = make_table(f, l, r, h)

print(trapezoidal(y_vals, h))
print(simpson_1_3(y_vals, h))
print(simpson_3_8(y_vals, h))