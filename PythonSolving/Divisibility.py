def foo(n, a):
    ans = 0
    for i in a:
        while i % 2 == 0:
            ans += 1
            i //= 2
            if ans >= n:
                print(0)
                return
    l = list()
    for i in range(1, n + 1):
        count = 0
        j = i
        while j % 2 == 0:
            count += 1
            j //= 2
        l.append(count)
    l = sorted(l, reverse=True)
    oper = 0
    for twos in l:
        if ans >= n:
            break
        ans += twos
        oper += 1
    if ans >= n:
        print(oper)
    else:
        print(-1)


t = int(input())
for i in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    foo(n, a)