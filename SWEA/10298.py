a = list(map(int, input().split()))
sum = 0
for i in range(2):
    if a[i] == a[i+1]:
        sum = sum + 1

if sum == 0:
    print('모두 다르다')
if sum == 2:
    print('모두 같다')
if 0 < sum < 2:
    print('일부 같다')