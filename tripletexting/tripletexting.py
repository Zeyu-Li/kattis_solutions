def main():
    text = input().strip()
    l = len(text) // 3

    result = []
    for i in range(l):
        if text[i] == text[i+l] or text[i] == text[i+2*l]:
            result.append(text[i])
        elif text[i+l] == text[i+2*l]:
            result.append(text[i+l])

    print(''.join(result))

    return

if __name__ == "__main__":
    main()
