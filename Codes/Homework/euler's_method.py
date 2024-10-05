import re

f = input().split("=")[1]
h = float(input().split("=")[1])
val = float(input().split("=")[1])

initial = input()
match = re.match(r'y\(([\d\.]+)\)\s*=\s*([\d\.]+)', initial)

x = float(match.group(1))
y = float(match.group(2))

while x < val:
    print("x =", x, "y =", y)
    y = y + h * eval(f)
    x += h
    
print("x =", x, "y =", y)