def main():
    n = int(input())
    for i in range(n):
        k = int(input())
        l = input().split()
        some_dict = dict()
        for item in l:
            if (item in some_dict.keys()): some_dict[item] = 2
            else: some_dict[item] = 1

        for key, value in some_dict.items():
            if value == 1:
                print(f'Case #{i+1}: {key}')
                break
    
    return

if __name__ == "__main__":
    main()
