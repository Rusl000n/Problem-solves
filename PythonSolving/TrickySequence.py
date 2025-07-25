def tricky_sequence(n):
    dp = [0] * ((2 * n) + 2)
    dp[0], dp[1], dp[2], dp[3] = 1, 1, 2, 4
    for i in range(4, n * 2, 2):
        dp[i] = dp[i // 2] + 1
        dp[i - 1] = dp[i] + dp[(i - 1) // 2]
    return dp[n]


n = int(input())
print(tricky_sequence(n))