def main():
    mappings = {}
    n = int(input())
    for _ in range(n):
        name, priority, date = input().split()
        priority = int(priority)
        # is same date and priority is better, replace
        if date in mappings.keys():
            # update if better
            if mappings[date][0] < priority:
                mappings[date] = [priority, name]
        else:
            mappings[date] = [priority, name]

    print(len(mappings))
    print('\n'.join(sorted([item[1] for item in mappings.values()])))

    return

if __name__ == "__main__":
    main()
