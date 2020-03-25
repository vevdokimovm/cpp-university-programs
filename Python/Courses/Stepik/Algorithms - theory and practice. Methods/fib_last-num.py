def fib_last_num(n, a = 0, b = 1):
    if n == 0:
        return a
    elif n == 1:
        return b
    else:
        for i in range(n - 1):
            a, b = b % 10, (b + a) % 10
    return b


n = int(input())
print(fib_last_num(n))
