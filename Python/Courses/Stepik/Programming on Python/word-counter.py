items = [word.lower() for word in input().split()]
d = {}

for i in range(len(items)):
    if items[i] not in d.keys():
        d[items[i]] = 1
    else:
        d[items[i]] += 1

for key, value in d.items():
    print(key, value)