def foo(a, b, c):
    gcd, x0, y0 = extended_gcd(a, b)
    if c % gcd != 0:
        return 0, 0
    x0 *= c // gcd
    y0 *= c // gcd
    if a != 0:
        if (b // gcd) != 0:
            k = -x0 // (b // gcd)
        else:
            k = 0
        x = x0 + k*(b//gcd)
        y = y0 -k*(a//gcd)
        while x < 0:
            x += b // gcd
            y -= a // gcd
        return x, y
    
    
def extended_gcd(a, b):
    if b == 0:
        return a, 1, 0
    else:
        gcd, x1, y1 = extended_gcd(b, a % b)
        x = y1
        y = x1 - (a // b) * y1
        return gcd, x, y
    

T = int(input())
ans = []
for j in range(T):
    a, b, c = map(int, input().split())
    ans.append(foo(a, b, c))
for i in ans:
    print(*i)