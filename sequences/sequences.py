# Too slow
# def backtrack(n: str) -> int:
#     if '?' not in n:
#         # base case
#         return 
#     # resolve first instance of ?
#     index = n.index('?')
#     n1 = n
#     n2 = n
#     n1[index] = '0'
#     n2[index] = '0'
#     return (int(backtrack(n1)) % 1000000007 + int(backtrack(n2)) % 1000000007) % 1000000007 

mod = 1000000007
cache = [1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096]

def sq_mod(n: int):
    '''
    gets how many it takes for inversion on n
    '''
    # generate more to cache
    while len(cache) <= n:
        cache.append((cache[-1] * 2) % mod)

    return cache[n]

def inversions(n: str):
    zeros = 0
    questions = 0
    total = 0
    for char in reversed(n):
        if char == '0': zeros+=1
        else:
            if char == '?': total*=2

            z = zeros * sq_mod(questions)
            q = 0 
            if questions != 0:
                q = questions * sq_mod(questions - 1)

            total = (total + z + q) % mod

            if char == '?': questions += 1

    return total

def main():
    # n = input()

    # print(backtrack(n))

    print(inversions(input()))

    return

if __name__ == "__main__":
    main()
