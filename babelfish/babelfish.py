import sys

lookup = False
lookups = {}
for line in sys.stdin:
    line = line.strip()
    if line == '':
        lookup = True
        continue
    if lookup:
        if line in lookups:
            print(lookups[line])
        else:
            print("eh")
    else:
        engl, foreign = line.split()
        lookups[foreign] = engl