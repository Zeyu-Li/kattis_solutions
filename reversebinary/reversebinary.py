num = int(input())

binary = bin(num)

print(int(binary[2:][::-1], 2))