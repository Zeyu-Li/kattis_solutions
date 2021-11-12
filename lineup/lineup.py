def main():
    n = int(input())
    p = []
    for _ in range(n):
        p.append(input())

    k = p.copy()

    k.sort()
    # print(k, p)
    
    if k == p:
        print("INCREASING")
        return
    
    
    # print(reversed(k), p, reversed(k) == p)
    if list(reversed(k)) == p:
        print("DECREASING")
    else:
        print("NEITHER")

    return

if __name__ == "__main__":
    main()
