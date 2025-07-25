def foo(l):
    proverk = []
    for i in l:
        if i in ['(', '[', '{']:
            proverk.append(i)
        elif i in [')', ']', '}']:
            if not proverk:
                return "no"
            top = proverk.pop()
            if (i == ')' and top != '(') or \
               (i == ']' and top != '[') or \
               (i == '}' and top != '{'):
                return "no"
    return "yes" if not proverk else "no"


l = input()
print(foo(l))