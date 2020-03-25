def count(list):
    if list == []:
        return 0
    return 1 + count(list[1:])

list = [1, 4, 6]

print(count(list))