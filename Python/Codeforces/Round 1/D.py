n, k = (int(i) for i in input().split())

items = [i for i in input().split()]
cnt = 0

for i in range(n):
    for j in range(i + 1, n):
        if i == j:
            continue
        if int(items[i] + items[j]) % k == 0:
            cnt += 1
        if int(items[j] + items[i]) % k == 0:
            cnt += 1


print(cnt)