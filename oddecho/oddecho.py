n = int(input())
l = []
for _ in range(n):
    l.append(input())

odd = True
for i in l:
    if odd: print(i)
    odd = not odd