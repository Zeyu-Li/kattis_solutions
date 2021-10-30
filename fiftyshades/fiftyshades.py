def main():
    n = int(input())

    count = 0
    for _ in range(n):
        line = input().lower()
        if 'rose' in line or 'pink' in line:
            count+=1

    print("I must watch Star Wars with my daughter" if count == 0 else count)

    return

if __name__ == "__main__":
    main()
