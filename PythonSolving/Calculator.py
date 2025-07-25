def foo(n):
    dp = [0] * (n + 1)
    parents = [-1] * (n + 1)

    for i in range(2, n + 1):

        dp[i] = dp[i - 1] + 1
        parents[i] = i - 1

        if i % 2 == 0 and dp[i // 2] + 1 < dp[i]:
            dp[i] = dp[i // 2] + 1
            parents[i] = i // 2

        if i % 3 == 0 and dp[i // 3] + 1 < dp[i]:
            dp[i] = dp[i // 3] + 1
            parents[i] = i // 3

    v = n
    ans = []
    while v != -1:
        ans.append(v)
        v = parents[v]
    print(dp[n])
    print(*ans[::-1])


n = int(input())
foo(n)