def foo(n):
    global l
    s = [1 for i in range(n + 2)]
    for i in range(2, n + 2):
        if s[i]:
            for j in range(i * i, n + 2, i):
                s[j] = 2
    l = len(s[2:])
    return  s[2:]
 
 
n = int(input())
l = 0
ans = foo(n)
if l > 2:
    print(2)
else:
    print(1)
print(*ans)
