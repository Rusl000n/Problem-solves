n = int(input())
w = [0] + list(map(int, input().split()))
s = sum(w)
if s % 2 != 0:
    print('NO')
else:
    dp = [[-1] * (s // 2 + 1) for i in range(n + 1)]
    dp[0][0] = 0
    for i in range(1, n + 1):
        for j in range(s // 2 + 1):
            dp[i][j] = dp[i - 1][j]
            if j - w[i] >= 0 and dp[i - 1][j - w[i]] != -1:
                dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i]] + w[i])
    if dp[-1][-1] != sum(w) // 2:
        print('NO')
    else:
        print('YES')