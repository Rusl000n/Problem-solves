def foo(ans, v, n):
    global t
    if (len(v) == 0):
        for i in ans:
            print(i, end=' ')
        print()
        t -= 1
        if (t == 0):
            exit()
    for i in v:
        if (i != n):
            v1 = list(v)
            v1.remove(i)
            foo(ans + [i], v1, n + 1)
            
            
n, t = map(int, input().split())
foo([], [i + 1 for i in range(n)], 1)