def main():
    n, t = list(map(int, input().split()))
    items = list(map(int, input().split()))

    if t == 1:
        print(7)
    elif t == 2:
        if items[0] == items[1]: print("Equal")
        else:
            print("Bigger" if items[0] > items[1] else "Smaller")
    elif t == 3:
        newItems = [items[0],items[1],items[2]]
        newItems.sort()
        print(newItems[1])

    elif t == 4:
        print(sum(items))
    elif t == 5:
        total = 0
        for item in items:
            total += 0 if item % 2 else item
        print(total)
    elif t == 6:
        mod26 = map(lambda x: x % 26, items)
        tochar = map(lambda x: chr(ord('a') + x), mod26)
        print(''.join(tochar))
    elif t == 7:
        index = items[0]
        items[0] = None
        while True:
            if index >= n:
                print('Out')
                break
            if index == n - 1:
                print('Done')
                break
            if items[index] == None:
                print('Cyclic')
                break
            items[index], index = None, items[index]
    return

if __name__ == "__main__":
    main()
