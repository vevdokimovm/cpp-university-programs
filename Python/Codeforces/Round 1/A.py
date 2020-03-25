n, k = (int(i) for i in input().split())

substr = input()
answer = substr

if n == 1:
    print(substr * k)
else:

    for i in range(k - 1):
        start = len(answer) - n + 1
        end = n - 1
        for j in range(n - 1):
            if answer[start:].find(substr[:end]) != -1:
                answer += substr[end:]
                break
            elif end == 1:
                answer += substr
            start += 1
            end -= 1

    print(answer)