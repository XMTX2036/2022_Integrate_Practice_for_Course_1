from math import gcd

def brute_force(a, n):    
    if gcd(a, n) != 1:
        return -1
    elif a > n:
        return brute_force(a%n, n)
    else:
        for i in range(1, n-1):
            if i*a%n == 1:
                return i

def ext_gcd(a, b):
    if b == 0:          
        return (1, 0)
    else:         
        (x, y) = ext_gcd(b, a % b)         
        x, y = y, (x - (a // b) * y)    
        return x, y

def Euclid(a, n):
    if gcd(a, n) != 1:
        return -1
    return (ext_gcd(a, n)[0]+n) % n

a, b = map(int, input().split())

# print(f'The multiplication inverse of {a} and {b} is {brute_force(a, b)}')
print(f'The multiplication inverse of {a} and {b} is {Euclid(a, b)}')