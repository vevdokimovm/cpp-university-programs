n = int(input())

coords = [0, 0]

for i in range(n):
    items = input().split()
    command = items[0]
    value = int(items[1])
    if 'север' == command:
        coords[1] += value
    elif 'юг' == command:
        coords[1] -= value
    elif 'восток' == command:
        coords[0] += value
    elif 'запад' == command:
        coords[0] -= value

print(*coords)