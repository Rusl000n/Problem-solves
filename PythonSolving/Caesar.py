def rimski_impaer(a, b, c, d):
    global dp
    if a == 0 and b == 0:
        return 1
    elif dp[a][b][c][d] == -1:
        summa = 0
        if a > 0 and c > 0:
            summa += rimski_impaer(a - 1, b, c - 1, k2) % 10 ** 8
        if b > 0 and d > 0:
            summa += rimski_impaer(a, b - 1, k1, d - 1) % 10 ** 8
        dp[a][b][c][d] = summa % 10 ** 8
    return dp[a][b][c][d]


n1, n2, k1, k2 = map(int, input().split())
dp = [[[[-1 for i in range(12)] for j in range(12)] for z in range(102)] for h in range(102)]
print(rimski_impaer(n1, n2, k1, k2) % 10 ** 8)