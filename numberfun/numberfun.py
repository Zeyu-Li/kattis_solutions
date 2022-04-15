cases = int(input())

for _ in range(cases):
    a, b, c = list(map(int, raw_input().split()))
    if a+b == c or a-b == c or a*b == c or b*c == a or b-a == c or c*a == b:
        print "Possible"
    else:
        print "Impossible"

