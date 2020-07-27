n = list(map(int, input().split()))
cnt = [0] * 10
for i in n:
    cnt[i] += 1
for i in range(len(cnt)):
    if cnt[i] == 1: print(i)