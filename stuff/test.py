l1 = [1,2,4,5,6,23423,335,2134,12,34]

def mapList(l):
    return {x:x for x in l}

def parseList(l):
    hasht = mapList(l)
    sl = sorted(l)

    for i in range(0, len(l)-1):
        for j in range(i, len(l) - 1):
            if (sl[i] + sl[j]) in hasht:
                return sl[i],sl[i+1]
    return False

# print(parseList(l1))


def isPalendrome(l):
    rl = l[::-1]
    for i in range(int(len(l)/2)):
        if rl[i] != l[i]:
            return False
    return True

# print(isPalendrome(input()))

def fib(n):
    if n == 0:
        return 1
    elif n == 1:
        return 1
    else:
        l=[]
        l.append(1)
        l.append(1)
        for i in range(2,n):
            l.append(l[i-1] + l[i-2]) 
        return l[n-1]
print(fib(int(input())))