
def main():
    i = input()
    while i != '-1':
        total = 0
        total_time = 0
        for _ in range(int(i)):
            speed, time = input().split()
            total += int(speed) * (int(time) - total_time)
            total_time = int(time)

        print(f'{total} miles')

        i = input()


if __name__ == "__main__":
    main()
