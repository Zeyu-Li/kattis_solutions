a = input()
out = ''

for index, char in enumerate(a):
    if char == '-':
        out+=a[index+1]

print(f"{a[0]}{out}")