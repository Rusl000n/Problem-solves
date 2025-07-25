n, m = map(int, input().split())
a = list(map(int, input().split()))
dp = [0] * (n + 1)
answer = set()

for i in range(n - 1, -1, -1):
    answer.add(a[i])
    dp[i] = len(answer)
for j in range(m):
    l = int(input())
    print(dp[l - 1])