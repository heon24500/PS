dummy = int(input())

a = input()
b = input()
if (len(a) < len(b)): a, b = b, a

max = 0
ret = ''
for start in range(len(b)):
    for end in range(start + 1, len(b)+1):
        tmp = b[start:end]
        if a.find(tmp) != -1 and max < len(tmp):
            max = len(tmp)
            ret = tmp
print(ret)