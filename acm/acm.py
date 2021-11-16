def main():
    score = 0
    count = 0
    teams = dict()
    teams_done = dict()
    while (1):
        curr = input()
        if curr == '-1':
            break

        time, team, state = curr.split()

        if state=='right':
            score += int(time)
            count += 1
            teams_done[team] = True
        else:
            if team in teams_done.keys(): continue
            if team in teams.keys(): teams[team] += 20
            else: teams[team] = 20

    for key, value in teams_done.items():
        if value:
            score += teams[key] if key in teams.keys() else 0

    print(count, score)

    return

if __name__ == "__main__":
    main()
