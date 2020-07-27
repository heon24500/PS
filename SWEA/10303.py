def SAMSUNG(a):
    return a.upper()

def MinCo(n):
    alpha = 'a'
    num = ord(alpha) + n - 1
    ch = chr(num)
    ch = SAMSUNG(ch)
    num = ord(ch) + 1
    ch = chr(num)
    return ch

n = int(input())
ret = MinCo(n)
print(ret)
