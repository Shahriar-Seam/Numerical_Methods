import re

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

f = input("Enter expression:\n").split('=')[1]
h = float(input("Enter h:\n").split('=')[1])
val = float(input("Enter stop value:\n").split('=')[1])

initial = input("Enter initial value of y [y(x0) = val]:\n")
match = re.match(r'y\(([\d\.]+)\)\s*=\s*([\d\.]+)', initial)

x = float(match.group(1))
y = float(match.group(2))
f = clean(f)

print(f"f = {f}")

print(eval(f))

while x < val:
    print("x =", x, "y =", y)
    y = y + h * eval(f)
    x += h
    
print("x =", x, "y =", y)