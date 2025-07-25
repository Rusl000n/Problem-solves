from math import inf
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


def foo(n, array, quest):
    dp = [- 1 for i in range(quest + 1)]
    dp[0] = 0
    p = [0 for i in range(quest + 1)]
    for i in range(quest + 1):
        a = inf
        for j in range(n):
            if array[j] <= i and dp[i - array[j]] != -1:
                if a > dp[i - array[j]]:
                    a = dp[i - array[j]]
                    dp[i] = a + 1
                    p[i] = i - array[j]
    print(dp[i])
    if dp[-1] != -1:
        a = quest
        while a != 0 and a != - 1:
            print(a - p[a], end=' ')
            a = p[a]


n = int(input())
array = list(reversed(merge_sort(list(map(int, input().split())))))
quest = int(input())
foo(n, array, quest)