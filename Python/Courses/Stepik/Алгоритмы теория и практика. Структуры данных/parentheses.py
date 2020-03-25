def is_closed(string):
    parentheses = []
    parentheses += string
    stack = []
    open_parens = ['(', '{', '[']
    close_parens = ['}', ']', ')']
    index = 0
    for paren in parentheses:
        index += 1
        if paren in open_parens:
            stack.append(paren)
        elif paren in close_parens:
            if len(stack) == 0:
                return index
            elif stack[len(stack)- 1] == '[' and paren == ']' or \
                 stack[len(stack) - 1] == '(' and paren == ')' or \
                 stack[len(stack) - 1] == '{' and paren == '}':
                del stack[len(stack) - 1]
            else:
                return index
    if len(stack) == 0:
        return 'Success'
    return index


string = input()
print(is_closed(string))
