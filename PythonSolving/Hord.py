def foo(n, queue, head):
    for j in range(n):
        line = input().split()
        command = line[0]

        if command == "+":
            i = int(line[1])
            queue.append(i)

        elif command == "*":
            i = int(line[1])
            mid = (len(queue) - head + 1) // 2
            queue.insert(head + mid, i)

        elif command == "-":
            print(queue[head])
            head += 1


n = int(input())
queue = []
head = 0
foo(n, queue, head)