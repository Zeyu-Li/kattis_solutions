def main():
    s = input().split(';')
    count = 0
    for i in s:
        if '-' in i:
            count+= int(i.split('-')[1]) - int(i.split('-')[0]) + 1
        else: count+= 1

    print(count)
    return

if __name__ == "__main__":
    main()
