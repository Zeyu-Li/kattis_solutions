n = int(input())
for _ in range(n):
    a = input()
    b = input()
    result = ''
    for c, d in zip(a, b):
        result += '.' if c == d else '*'

    print(a)
    print(b)
    print(result)
    print()