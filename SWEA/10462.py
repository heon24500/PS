n = int(input())

for i in range(n):
    a = input()

    ret = ''
    for j in range(len(a)):
        if j == 0:
            ret += a[j]
        elif j == 1:
            if a[j-1] == '^' and a[j+1] == '^' and a[j] != '^' and a[j] != '_': ret += '_'
            elif a[j] == '^': ret += a[j]
            else:
                if a[j-1] != a[j]: ret += a[j]
        elif j == len(a) - 1:
            if a[j] == '^' and a[j-2] != a[j]: ret += a[j]
            else:
                if a[j] != a[j-1]: ret += a[j]
        else:
            if a[j - 1] == '^' and a[j + 1] == '^' and a[j] != '^' and a[j] != '_': ret += '_'
            elif a[j] == '^' and a[j-2] != a[j]: ret += a[j]
            else:
                if a[j] != a[j-1]: ret += a[j]
    print(ret)