from math import gcd

def my_gcd(x, y):
    if y == 0:
        return x
    else:
        return my_gcd(y, x%y)

a, b = map(int, input().split())
if my_gcd(a, b) == gcd(a, b):
    print(f'The result is correct: ({a}, {b}) = {gcd(a, b)}')
else:
    print(f'The result is wrong!')