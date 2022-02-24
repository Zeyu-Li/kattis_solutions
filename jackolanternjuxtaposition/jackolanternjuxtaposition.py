from functools import reduce
def main():
    nums = map(int, input().split())
    print(reduce(lambda x,y: x*y, nums))
    return

if __name__ == "__main__":
    main()
