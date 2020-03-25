def modify_list(items):
    for i in range(len(items)):
        if items[i] % 2 == 0:
            items[i] //= 2
        else:
            del items[i]

lst = [1, 2, 3, 4, 5, 6]
modify_list(lst)
print(lst)