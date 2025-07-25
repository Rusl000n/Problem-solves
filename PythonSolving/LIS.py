def task(arr):
    dp = list()
    if len(arr) == 0:
        return 0
    for i in arr:
        l, r = 0, len(dp)
        while l < r:
            mid = (l + r) // 2
            if dp[mid] < i:
                l = mid + 1
            else:
                r = mid
        if l == len(dp):
            dp.append(i)
        else:
            dp[l] = i
    print(len(dp))


def make_arr(n, a1, k, b, m):
    arr = [0] * n
    arr[0] = a1
    for i in range(1, n):
        arr[i] = (k * arr[i - 1] + b) % m
    return arr


n, a1, k, b, m = map(int, input().strip().split())
arr = make_arr(n, a1, k, b, m)
task(arr)