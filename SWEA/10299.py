a = int(input())
b = list(map(int, input().split()))

for i in range(len(b)):
    if i == a:
        print('change', end=' ')
    else:
        print(b[i], end=' ')