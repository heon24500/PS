p = [['A', 'B', 'C', 'D', 'E'], ['B', 'B', 'B', 'C', 'C'], ['C', 'C', 'C', 'B', 'B'], ['C', 'C', 'C', 'B', 'B'], ['B', 'B', 'B', 'C', 'C']]

def garo(st):
    cnt = 0
    for i in range(5):
        for j in range(3):
            pst = ''
            for k in range(3):
                pst += p[i][j + k]
            if pst == st: cnt += 1
    return cnt

def daegak(st):
    cnt = 0
    for i in range(3):
        for j in range(3):
            pst = ''
            for k in range(3):
                pst += p[i + k][j + k]
            if pst == st: cnt += 1
    return cnt

def saero(st):
    cnt = 0
    for i in range(3):
        for j in range(5):
            pst = ''
            for k in range(3):
                pst += p[i + k][j]
            if pst == st: cnt += 1
    return cnt

n = int(input())

d = dict()
for i in range(n):
    a = input()
    d[a] = garo(a) + daegak(a) + saero(a)
    print(a, d[a])