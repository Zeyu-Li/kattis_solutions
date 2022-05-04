a = input()
length = len(a)
white = 0
lower = 0
upper = 0
other = 0
for char in a:
    if char == '_':
        white += 1
    elif char.isupper():
        upper+=1
    elif char.islower():
        lower+=1
    else:
        other+=1

print(white/length)
print(lower/length)
print(upper/length)
print(other/length)