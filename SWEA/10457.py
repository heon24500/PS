n = int(input())

d = dict()
d['A'] = []
d['B'] = []
d['C'] = []

for i in range(n):
    a = input().split()
    if a[0] == 'A' or a[0] == 'B' or a[0] == 'C':
        if not a[1] in d[a[0]]: d[a[0]].append(a[1])
    else:
        if not a[0] in d[a[1]]: d[a[1]].append(a[0])

g = input()
for i in d[g]:
    print(i, end=' ')