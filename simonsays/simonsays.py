def main():
    n = int(input())

    for _ in range(n):
        s = input()
        if "Simon says" == s[:10]:
            print(s[10:])
    return

if __name__ == "__main__":
    main()
