from math import gcd, lcm
 
ans = list()
t = int(input())
for i in range(t):
    n = int(input())
    b = [0 for i in range(n + 1)]
    a = list(map(int, input().split()))
    if len(a) <= 2:
        print('YES')
    else:
        b[0], b[-1] = a[0], a[-1]
        for i in range(1, n):
            b[i] = lcm(a[i - 1], a[i])
        for i in range(1, n):
            if gcd(b[i - 1], b[i]) == a[i - 1]:
                c = True
            else:
                c = False
                break
        if c is True:
            print('YES')
        else:
            print('NO')
