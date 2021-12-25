a = input()
items = map(int, input().split())

new_items = list(filter(lambda x: x>=0, items))
# print(list(new_items))
# print(new_items)

print(sum(new_items)/len(new_items))