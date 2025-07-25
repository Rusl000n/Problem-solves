n = int(input())
w = [int(x) for x in input().split()]
ans = sum(w)
for i in range(2 ** (n - 1), 2 ** n):
    mask = bin(i)[2:]
    sm0 = 0
    sm1 = 0
    for j in range(n):
        if mask[j] == '0':
            sm0 += w[j]
        else:
            sm1 += w[j]
    ans = min(ans, abs(sm0 - sm1))
print(ans)