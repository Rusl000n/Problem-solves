s, n = map(int, input().split())
w = [0] + list(map(int, input().split()))
dp = [[-1] * (s + 1) for i in range(n + 1)]
dp[0][0] = 0
for i in range(1, n + 1):
    for j in range(s + 1):
        dp[i][j] = dp[i - 1][j]
        if j - w[i] >= 0 and dp[i - 1][j - w[i]] != -1:
            dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i]] + w[i])
print(max(max(dp)))