def hanoi(n, start, end):
  if n > 0:
    temp = 6 - start - end
    hanoi(n - 1, start, temp)
    print(n, start, end)
    hanoi(n - 1, temp, end)

n = int(input())
hanoi(n, 1, 3)
