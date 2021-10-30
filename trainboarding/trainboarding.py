def main():
    n, l, p = map(int, input().split())

    ppl = []
    for _ in range(p):
        ppl.append(int(input()))

    _max = 0
    groups = dict()
    for person in ppl:
        door = (person//l)
        door = min(door, n-1)
        # print(door, person, person//l)
        _max = max(_max, abs(door*l+l//2-person))
        if (door in groups.keys()):
            groups[door] += 1
        else:
            groups[door] = 1


    print(_max)
    print(max(groups.values()))

    return

if __name__ == "__main__":
    main()