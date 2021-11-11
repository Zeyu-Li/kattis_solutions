val = {
    'T': 0,
    'C': 0,
    'G': 0
}
value_key = {
    'T': 3,
    'C': 2,
    'G': 1
}

s = input()

_sum = 0

for char in s:
    val[char]+=1

_min = min(val.values())
for key, value in val.items():
    # val[key] -= _min
    if val[key] != 0:
        _sum+=value**2

print(_min*7 + _sum)
