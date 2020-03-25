d = int(input())
known_words = list()

for i in range(d):
    known_words += [input().lower()]

l = int(input())
text = list()

for i in range(l):
    text.append(input().lower().split())

printed = list()

for i in range(l):
    for j in range(len(text[i])):
        if text[i][j] not in known_words and text[i][j] not in printed:
            print(text[i][j])
            printed.append(text[i][j])
