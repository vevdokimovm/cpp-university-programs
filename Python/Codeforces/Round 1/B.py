n = int(input())

costs = [int(i) for i in input().split()]
answer = 0
cnt = 1

for i in range(1, n):
    value = costs[i - 1] * 2
    if costs[i] <= value:
        cnt += 1
    elif cnt > answer:
        answer = cnt
        cnt = 1
print(answer)