def main():
    # divide into two segments, above sqrt(200 000) 
    # where it does it by updating the array and below sqrt(200 000) where it buckets
    # the mods and adds them up

    half = 447
    n, q = map(int, input().split())
    large = [0 for _ in range(n+1)]
    mods = dict()
    for i in range(q):
        items = list(map(int, input().split()))

        if items[0] == 2:
            curr = 0
            if items[1] > half:
                curr += large[items[1]]
                
            for key, value in mods.items():
                curr += value[items[1] % key]

            print(curr)

        else:
            _, a, b, c = items
            if b > half:
                for i in range(a % b, n+1, b):
                    large[i] += c
            else:
                if b in mods.keys():
                    # add to table b, c at row a % b
                    mods[b][a % b] += c
                else:
                    # initialize table to all 0s
                    new_dict = [0 for i in range(b)]
                    new_dict[a % b] = c
                    mods[b] = new_dict

    return

if __name__ == "__main__":
    main()
