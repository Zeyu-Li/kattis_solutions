
def main():
    case_number = input()

    # turned lists -> sets thx to https://github.com/JonSteinn/Kattis-Solutions/blob/master/src/Proofs/Python%203/main.py
    # see tests to see a way to do it that is not efficient
    TRUE = set()
    assumptions = True
    for line_number in range(int(case_number)):
        statement = input()

        # check to see if it is an assumption
        if statement[0] == '-':
            # if it is an assumption, append to truths
            TRUE.add(statement[3:])

        # proof part
        else:
            premises, conclusion = statement.split(' -> ')
            if all(premise in TRUE for premise in premises.split()):
                TRUE.add(conclusion)
            else:
                print(line_number + 1)
                return

    print('correct')


if __name__ == "__main__":
    main()
