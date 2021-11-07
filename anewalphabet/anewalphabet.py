def main():
    mapping = {
        'a': '@',
        'b': '8',
        'c': '(',
        'd': '|)',
        'e': '3',
        'f': '#',
        'g': '6',
        'h': '[-]',
        'i': '|',
        'j': '_|',
        'k': '|<',
        'l': '1',
        'm': '[]\/[]',
        'n': '[]\[]',
        'o': '0',
        'p': '|D',
        'q': '(,)',
        'r': '|Z',
        's': '$',
        't': "']['",
        'u': '|_|',
        'v': '\/',
        'w': '\/\/',
        'x': '}{',
        'y': '`/',
        'z': '2',
    }
    
    ask = input().lower()
    out = ''
    for char in ask:
        if char in mapping.keys():
            out+=mapping[char]
        else: 
            out+=char
    
    print(out)

if __name__ == "__main__":
    main()
