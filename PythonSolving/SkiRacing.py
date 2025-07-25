def Make_Results(x):
    global n, L
    n += 1
    return n + x*L


def merge_sort(elem1, elem2):
    global cnt
    answer = [0] * (len(elem1) + len(elem2))
    i, j = 0, 0
    while i < len(elem1) or j < len(elem2):
        if i == len(elem1):
            answer[i + j] = elem2[j]
            j += 1
        elif j == len(elem2):
            answer[i + j] = elem1[i]
            i += 1
        elif elem1[i] > elem2[j]:
            answer[i + j] = elem2[j]
            cnt += len(elem1) - i
            j += 1
        else:
            answer[i + j] = elem1[i]
            i += 1
    return answer


def sort(array):
    if len(array) < 2:
        return array
    mid = len(array) // 2
    return merge_sort(sort(array[:mid]), sort(array[mid:]))


N, L = map(int, input().split())
n = -1
place = 0
cnt = 0
results = list(map(Make_Results,
                   list(map(int, input().split()))))
sort(results)
print(cnt)
