def is_balanced(sequence):
    stack = []
    opening_brackets = "([{"
    closing_brackets = ")]}"

    for character in sequence:
        if character in opening_brackets:
            stack.append(character)
        elif character in closing_brackets:
            if not stack or stack.pop() != opening_brackets[closing_brackets.index(character)]:
                return False

    return not stack

sequence = input()
if is_balanced(sequence):
    print("yes")
else:
    print("no")
