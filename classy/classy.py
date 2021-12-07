# from operator import itemgetter
def spliter(item):
    return item.split('-')
def getVal(item):
    if item == 'upper': return '2'
    elif item == 'middle': return '1'
    else: return '0'
# def comparer(item1, item2):
#     if item1[1] == item2[1]:
#         return 1 if item1[0] > item2[0] else -1
#     return 1 if item1[1] > item2[1] else -1
# def sort_dict(dic):
#     items = []
#     for key, value in dic.items():

class Person:
    def __init__(self, val, name):
        self.val = val
        self.name = name

    # def __cmp__(self, other):
    #     if other.val == self.val:
    #         return 1 if self.name > other.name else -1
    #     return 1 if self.val > other.val else -1

    def __lt__(self, other):
        if other.val == self.val:
            return self.name > other.name
        return self.val < other.val

    def __str__(self):
        return self.name

    def __repr__(self):
        return self.name

def main():
    cases = int(input())
    for _ in range(cases):
        num_items = int(input())
        items = dict()
        for _ in range(num_items):
            name, cl, _ = input().split()
            # print(reversed(list(map(getVal, cl.split('-')))))
            items[name[:-1]] = cl.split('-')

        max_len = max(map(len, items.values()))
        
        new_items = []
        for key, value in items.items():
            new_items.append(Person(int(''.join(list(map(getVal, value))).rjust(max_len, '1')[::-1]), key)) 
            # val = 0
            # for i, val in enumerate(value):
            #     if val == 'upper':
            #         val += 2 ** i
            #     elif val == 'upper':
            # new_items[key] = sum([ for i, val in enumerate(value)])
            
        
        # print(new_items)
        # new_items.items().sort()
        new_items.sort(reverse=True)
        # print('\n'.join(new_items))
        print('\n'.join(str(item) for item in new_items))

        print('='*30)
    return

if __name__ == "__main__":
    main()
