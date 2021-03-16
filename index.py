'''
File Type Gen by Andrew Li
Generate a List of Files along With File Type
'''

import os
# requires pyperclip to copy to clipboard, otherwise, leave it in
# import pyperclip


def main():
    files = os.listdir()

    # remove non folder items manually
    ignore = ['.git', '.gitignore', 'generate.py', 'index.py', 'LICENSE.txt', 'README.md']

    for item in ignore:
        files.remove(item)

    # inits
    text = '\n'
    mapping = {'py': 'Python', '.c': 'C', 'pp': 'C++'}

    # generate clipboard items
    for _file in files:
        file_types = ''
        # find file type
        items = os.listdir(_file)
        for item in items:
            if item[-2:] in mapping.keys():
                file_types += mapping[item[-2:]] + ', '

        text += f"* [{_file}](https://open.kattis.com/problems/{_file}) - {file_types[:-2]} \n"

    front = """# Kattis (Competitive Programming)

[Kattis](https://open.kattis.com/) is a repository of competitive programming questions (coding challenges). You can then submit your code and it will be evaluated



## Questions """

    end = """


## License

MIT"""

    # debug
    # print(text)
    # pyperclip.copy(text)

    # write to file README.md
    with open('README.md', 'w') as fp:
        fp.writelines(front + text + end)

    return 

if __name__ == "__main__":
    main()
