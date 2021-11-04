def main():
    chars = input()
    stack = []
    for char in chars:
        if char == '<':
            # pop from stack
            if len(stack) != 0:
                stack.pop()
        else:
            stack.append(char)
    
    print(''.join(stack))
    

if __name__ == "__main__":
    main()
