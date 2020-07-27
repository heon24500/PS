def AA(a):
    print(a.upper(), end=' ')
def BB(n):
    n = int(n)
    n += 10
    print(n, end=' ')
st = input().split()
if st[0].isdigit():
    AA(st[1])
    BB(st[0])
else:
    AA(st[0])
    BB(st[1])