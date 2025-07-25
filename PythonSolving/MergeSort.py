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


s = int(input())
sps = list(map(int, input().split()))
print(*merge_sort(sps))