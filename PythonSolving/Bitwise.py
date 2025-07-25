def radix(arr):
    if not arr:
        return []
    max_abs_val = max(abs(x) for x in arr)
    dig = 0
    if max_abs_val == 0:
        dig = 1
    else:
        dig = len(str(max_abs_val))

    for i in range(dig):
        buckets = [[] for _ in range(10)]
        for num in arr:
            digit_val = (abs(num) // (10 ** i)) % 10
            buckets[digit_val].append(num)

        arr = []
        for j in buckets:
            arr.extend(j)
    negative = [x for x in arr if x < 0]
    positive = [x for x in arr if x >= 0]
    negative.sort(reverse=True)
    negative = [-x for x in negative]
    positive.sort()
    return negative + positive


n = int(input())
arr = list(map(int, input().split()))
print(*radix(arr))