# https://www.andrew.cmu.edu/course/15-200/s06/applications/ln/junk.html
# https://condor.depaul.edu/ichu/csc415/notes/notes9/Infix.htm

precedence_stack = {
    '(' : 0,
    '+' : 2,
    '-' : 2,
    '*' : 4,
    '/' : 4,
    '^' : 8,
    'neg' : 9,
}

precedence_input = {
    '(' : 10,
    ')' : 0,
    '+' : 1,
    '-' : 1,
    '*' : 3,
    '/' : 3,
    '^' : 7,
    'neg' : 9,
}

operators = set('+-*/^')

def clean(s):
    output = ""
    
    for i in range(len(s)):
        if i > 0 and (s[i] == 'x' or s[i] == 'y'):
            if len(output) > 0 and output[-1] not in '+-*/ (':
                output += "*"
            output += s[i]
        else:
            output += s[i]
    
    return output
    

def infix_to_postfix(s):
    s = clean(s)
    
    output = []
    s = s + ')'
    stack = ['(']
    prev_c = '('
    
    has_num = False
    num = 0
    has_var = False
    variable = ''
    
    for c in s:
        if c == ' ':
            continue
        
        if c.isdigit():
            has_num = True
            num = num * 10 + int(c)
            prev_c = c
            continue
        
        if has_num:
            has_num = False
            output.append(num)
            num = 0
        
        if c.isalpha():
            has_var = True
            variable += c
            prev_c = c
            continue
            
        if has_var:
            has_var = False

            if variable in {'x', 'y'}:
                output.append(variable)
            variable = ''
        
        if c == '-' and (prev_c == '(' or prev_c in operators) and (prev_c not in {'x', 'y'}):
            c = 'neg'
            
        while precedence_stack[stack[-1]] >= precedence_input[c]:
            popped = stack.pop()
            
            if popped != '(':
                output.append(popped)
            else:
                break
        
        if c != ')':
            stack.append(c)
        
        prev_c = c
        
    return output

def evaluate_postfix(postfix, x = 0, y = 0):
    stack = []
    
    for token in postfix:
        if token not in precedence_input:
            if token == 'x':
                stack.append(x)
            elif token == 'y':
                stack.append(y)
            else:
                stack.append(token)
            continue
        
        if token == '+':
            stack.append(stack.pop() + stack.pop())
        elif token == '-':
            a, b = stack.pop(), stack.pop()
            stack.append(b - a)
        elif token == '*':
            stack.append(stack.pop() * stack.pop())
        elif token == '/':
            a, b = stack.pop(), stack.pop()
            stack.append(b / a)
        elif token == '^':
            a, b = stack.pop(), stack.pop()
            stack.append(b ** a)
        elif token == 'neg':
            stack.append(-stack.pop())

    return stack[0]

def derivative(f, x, h = 1e-6):
    return (evaluate_postfix(f, x + h) - evaluate_postfix(f, x)) / h

# s = input()

# print(s)

# post = infix_to_postfix(s)

# print(''.join(str(i) for i in post))

# print(evaluate_postfix(post, x = 3, y = 1))