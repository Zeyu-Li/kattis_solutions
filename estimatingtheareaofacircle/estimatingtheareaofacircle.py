import math

def main():
    while 1:
        # r= radius, m = total, c = within circle
        r, m, c = map(float, input().split())

        if r == 0 and m == 0 and c == 0:
            break

        print(math.pi * r*r, 4 * r * r*c/m)

    return

if __name__ == "__main__":
    main()
