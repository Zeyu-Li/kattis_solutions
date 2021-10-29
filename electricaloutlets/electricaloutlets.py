
n = int(input())
for _ in range(n):
    items = list(map(int, input().split()[1:]))
    print(sum(items)-len(items)+1)
    