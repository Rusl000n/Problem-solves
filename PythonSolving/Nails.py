def merge(a, b):
  c = [0] * (len(a) + len(b))
  i = j = 0
  while i < len(a) or j < len(b):
    if i == len(a):
      c[i + j] = b[j]
      j += 1
    elif j == len(b):
      c[i + j] = a[i]
      i += 1
    elif a[i] > b[j]:
      c[i + j] = b[j]
      j += 1
    else:
      c[i + j] = a[i]
      i += 1
  return c


def merge_sort(sps):
  if len(sps) < 2:
    return sps
  mid = len(sps) // 2
  return merge(merge_sort(sps[:mid]), merge_sort(sps[mid:]))

def carnation_flowers(n, array):
    dp = [0] * 102
    dp[1] = array[1] - array[0]
    if n > 2:
        i = 3
        dp[2] = array[2] - array[1] + dp[1]
        while i < n:
            dp[i] = dp[i - 1] + array[i] - array[i - 1]
            if dp[i - 2] + array[i] - array[i - 1] < dp[i]:
                dp[i] = dp[i - 2] + array[i] - array[i - 1]
            i += 1
    return dp[n - 1]


n = int(input())
m = merge_sort(list(map(int, input().split())))
print(carnation_flowers(n, m))