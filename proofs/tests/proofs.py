
def main():
    case_number = input()

    TRUE = []
    assumptions = True
    for line_number in range(int(case_number)):
        statement = input()

        # check to see if it is an assumption
        if statement[0] == '-':
            # if it is an assumption, append to truths
            TRUE.append(statement[3:])

        # proof part
        else:
            premises, conclusion = statement.split(' -> ')
            
            for premise in premises.split(' '):
                if premise not in TRUE:
                    print(line_number + 1)
                    return

            TRUE.append(conclusion)

    print('correct')


if __name__ == "__main__":
    main()
