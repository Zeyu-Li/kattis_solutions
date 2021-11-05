def main():
    a, b = map(int, input().split())

    if a == 0 and b == 0:
        print("Not a moose")
    else:
        if a==b:
            print(f"Even {2*a}")
        else:
            print(f"Odd {max(a,b) * 2}")
    return

if __name__ == "__main__":
    main()
