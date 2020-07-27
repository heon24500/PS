n = int(input())
cnt = 0
for i in range(n):
    s = input()
    for j in range(len(s) - 4):
        st = s[j:j+5]
        if st == 'MINCO': cnt += 1
print(cnt)