def bin_research(i, b):
  left = -1
  right = len(b)
  while left+1 < right:
    m = (left+right)//2
    if b[m] < i:
      left = m
    else:
      right = m
  if right == len(b):
    right -=1
  if right == left:
    return [b[left], 0]
  else:
    return ([b[left], abs(b[left]-i)]
            if abs(b[left]-i) < abs(b[right] - i)
            else [b[right], abs(b[right] - i)])


def task(a, b, answer):
  for i in range(len(a)):
    j, defference = map(int, bin_research(a[i], b))
    if abs(a[i] - j) < abs(answer[0] - answer[1]):
      answer[0] = a[i]
      answer[1] = j
    if defference == 0:
      return answer
  return answer


m0 = int(input())
a = list(map(int, input().split()))
m1 = int(input())
b = list(map(int, input().split()))
answer = [a[0], b[0]]
print(*task(a, b, answer))