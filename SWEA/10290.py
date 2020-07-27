lst = list(map(int, input().split()))
sum = 0

for i in range(len(lst)):
    if lst[i] == 7:
        print('lucky')
    else:
        sum = sum + lst[i]

print(sum)