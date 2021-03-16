def main():
    high = 0
    high_index = 0

    for i in range(5):
        l = list(map(int, input().split()))
        score = 0
        for item in l:
            score += item

        if score > high:
            high =score
            high_index = i

    print(f"{high_index+1} {high}")


    return

if __name__ == "__main__":
    main()
