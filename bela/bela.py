from sys import stdin

dominant = {'A': 11, 'K': 4, 'Q':3, 'J':20, 'T':10,'9':14}
nondominant = {'A': 11, 'K': 4, 'Q':3, 'J':2, 'T':10,'9':0}

total = 0
for k, i in enumerate(stdin):
    if k == 0:
        _, dominant_suit = i.split()
    else:
        i = str(i)
        if i[0] in ['7', '8']:
            continue
        if i[1] == dominant_suit:
            total += dominant[i[0]]
        else:
            total += nondominant[i[0]]

print(total)
