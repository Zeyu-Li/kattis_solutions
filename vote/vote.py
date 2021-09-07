def main():
    cases = int(input())
    for _ in range(cases):
        candidates = int(input())
        votes = []
        for _ in range(candidates):
            votes.append(int(input()))

        # if majority is found, print the candidate
        if (max(votes) > sum(votes) / 2):
            print(f"majority winner {votes.index(max(votes)) + 1}")

        # if no majority, print the candidate with the fewest votes
        # 1 winner
        elif (votes.count(max(votes)) == 1):
            print(f"minority winner {votes.index(max(votes)) + 1}")
        # more than 1 winner
        else:
            print("no winner")


if __name__ == "__main__":
    main()
