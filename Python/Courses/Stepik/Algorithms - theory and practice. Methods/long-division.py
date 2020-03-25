def fib(n):
    sqrt5 = 5 ** 0.5
    phi = (1 + sqrt5) / 2
    psi = (1 - sqrt5) / 2
    return int((phi ** n - psi ** n) / sqrt5)


str = [int(i) for i in input().split()]
print(fib(str[0]) % int(str[1]))