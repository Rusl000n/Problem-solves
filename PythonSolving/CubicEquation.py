def cud_equation(x):
    global a, b, c, d
    return a * (x**3) + b * (x**2) + c * x + d


def bin_search():
    left = -1000000000000
    right = 1000000000000
    for i in range(10000):
        middle = (left + right) / 2
        if cud_equation(left) * cud_equation(middle) > 0:
            left = middle
        else:
            right = middle
    print(left)


a, b, c, d = map(int, input().split())
bin_search()