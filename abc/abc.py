nums = list(map(int, input().split()))

nums.sort()

sortKey = input()

items = []
mapping = {'A': 0, 'B': 1, 'C': 2}
for char in sortKey:
    items.append(nums[mapping[char]])

print(items[0], items[1], items[2])