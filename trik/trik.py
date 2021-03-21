def main():
    counts = input()

    a = [1,0,0]
    for char in counts:
        if char == 'A':
            a[0], a[1] = a[1], a[0]
        elif char == 'B':
            a[1], a[2] = a[2], a[1]
        else:
            a[0], a[2] = a[2], a[0]
    
    # print(a)
    for index, i in enumerate(a):
        if i == 1:
            print(index+1)
            break

    return

if __name__ == "__main__":
    main()
