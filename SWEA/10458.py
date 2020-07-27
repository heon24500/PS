n = int(input())
lst = list(map(int, input().split()))

lst = lst[:n + 1]
max = 0
cnt = 0
for i in range(len(lst)-1, -1, -1):
    if lst[i] >= max:
        cnt += 1
        max = lst[i]

print(cnt)