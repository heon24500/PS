n = int(input())
lst = []
for i in range(1, n + 1, 1):
    lst.append((i * 3))

lst.reverse()
for i in range(n):
    print(lst[i], end=' ')