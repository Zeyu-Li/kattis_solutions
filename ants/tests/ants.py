from math import ceil
import sys

# python literally unusable

def main():
    for i in sys.stdin:
        _input = i.split()
        cases = int(_input[0])

        # notice if a ant hits another ant, it is as if they passed through each other
        index = 1
        for n in range(cases):
            length, ant_count = _input[index], _input[index + 1]
            length = int(length)

            index += 1

            all_ants = []
            for _ in range(int(ant_count)):
                all_ants.append(int(_input[index]))
                index += 1

            maximum = max(all_ants)
            minimum = min(all_ants)

            _min = int(length / 2 - min([abs(length / 2 - ant) for ant in all_ants]))
            _max = maximum if maximum >= length - minimum else length - minimum

            print(_min, _max)

if __name__ == "__main__":
    main()
