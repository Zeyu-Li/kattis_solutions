def main():
    a, b, c = input().split()

    operations = ['+', '-', '*','/']

    for operation in operations:        
        if (eval(a+operation+b) == int(c)):
            print(a+operation+b+'='+c)
            break
        if (eval(b+operation+c) == int(a)):
            print(a+'='+b+operation+c)
            break
    return 0

if __name__ == "__main__":
    main()
