n = int(input())
for i in range(1, n+1, 1):
    num = str(i)
    cnt = 0
    for j in num:
        if j == '3' or j == '6' or j == '9':
            print('¦', end='')
            cnt += 1
    if cnt == 0:
        print(i, end=' ')
    else:
        print(end=' ')
