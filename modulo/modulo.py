def main():
    a=set()
    for _ in range(10):
        a.add(int(input()) % 42)
    
    print(len(a))
    return

if __name__ == "__main__":
    main()
