a1, code, encode, decode = input(), input(), input(), input()

manual = {}

manual['encode'] = {a1[i]: code[i] for i in range(len(a1))}
manual['decode'] = {code[i]: a1[i] for i in range(len(code))}

encoded = ''
decoded = ''

for i in range(len(encode)):
    encoded += manual['encode'][encode[i]]

for i in range(len(decode)):
    decoded += manual['decode'][decode[i]]

print(encoded, decoded, sep='\n')