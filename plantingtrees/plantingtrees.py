def main():
    n = input()
    trees = list(map(int, input().split()))

    trees.sort(reverse=True)

    curr = 0
    _max = trees[0]
    for tree in trees:
        if tree > _max:
            curr += 1
            _max += 1

        _max-=1

    print(curr + trees[0] + 2)

    return

if __name__ == "__main__":
    main()
