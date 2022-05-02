import sys

def main():
    for n in sys.stdin:
        print("{0:.2f}".format(eval(n)))
    
    return

if __name__ == "__main__":
    main()
