a = list(map(int, input().split()))
sum = 0
for i in range(2):
    if a[i] == a[i+1]:
        sum = sum + 1

if sum == 0:
    print('��� �ٸ���')
if sum == 2:
    print('��� ����')
if 0 < sum < 2:
    print('�Ϻ� ����')