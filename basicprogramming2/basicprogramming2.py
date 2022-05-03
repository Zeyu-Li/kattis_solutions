def main():
    n, t = list(map(int, input().split()))
    items = list(map(int, input().split()))

    if t == 1:
        items.sort()
        for item in items:
            c = 7777-item
            if c in items:
                print("Yes")
                return
            # for j in range(i + 1, n):
            #     if items[i] + items[j] == 7777:
            #         print("Yes")
            #         return
        # for i in range(n):
        #     for j in range(i + 1, n):
        #         if items[i] + items[j] == 7777:
        #             print("Yes")
        #             return
        print("No")
    elif t == 2:
        if len(set(items)) == len(items): print("Unique")
        else: print("Contains duplicate")
    elif t == 3:
        # if len(set(items)) < len(items) // 2: print(-1)
        # else: print("Contains duplicate")
        counts = {}
        for item in items:
            if item in counts:
                counts[item]+=1
            else:
                counts[item]=1
        for k, v in counts.items():
            if v > len(items) // 2:
                print(k)
                break
            else:
                print(-1)

    elif t == 4:
        items.sort()
        if len(items) == 1:
            print(items[0])
        elif len(items) % 2:
            print(items[len(items)//2 - 1])
        else:
            print(items[len(items)//2 - 1], items[len(items)//2])
    elif t == 5:
        newList = []
        for item in items:
            if 100 <= item <= 999:
                newList.append(item)

        newList.sort()
        print(' '.join(map(str, newList)))
    return

if __name__ == "__main__":
    main()
