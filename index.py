'''
File Type Gen by Andrew Li
Generate a List of Files along With File Type
'''

import os
# requires pyperclip to copy to clipboard, otherwise, leave it in
# import pyperclip
from bs4 import BeautifulSoup
from urllib.request import Request, urlopen

USERNAME = "zeyu-li"

def get_score():
    # BeautifulSoup (I know it has a dependency but I want to learn bs4)
    url = "https://open.kattis.com/users/" + USERNAME
    req = Request(url, headers={'User-Agent': 'Mozilla/5.0'})
    soup = BeautifulSoup(urlopen(req).read(), features="lxml")
    # print(soup.find(class_='rank').table.select('tr')[1].get_text().split())
    
    return soup.find(class_='rank').table.select('tr')[1].get_text().split()


def main():
    files = os.listdir()

    # remove non folder items manually
    ignore = ['.git', '.gitignore', '.github', 'index.py', 'LICENSE.txt', 'README.md', 'generate.py']

    print(files)
    print(os.getcwd())
    for item in ignore:
        if item in files: files.remove(item)

    # inits
    text = '\n'
    mapping = {'py': 'Python', '.c': 'C', 'pp': 'C++', 'va': "Java"}

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

![Build](https://github.com/Zeyu-Li/kattis_solutions/workflows/Generate%20MD/badge.svg)

[Kattis](https://open.kattis.com/) is a repository of competitive programming questions (coding challenges). You can then submit your code and it will be evaluated



## Questions """

    end = """


## License

MIT"""

    # debug
    # print(text)
    # pyperclip.copy(text)

    score = '🤷‍♂️' 
    try:
        rank, kattis_score = get_score()
        score = f'## Ranking\nScore: **{kattis_score}**\nRank: **{rank}**\n'
    except:
        # optionally throw an exception here
        pass

    # write to file README.md
    with open('README.md', 'w') as fp:
        fp.writelines(front + text + f"\nCount: {len(files)}\n\n" + score + end)

    return 

if __name__ == "__main__":
    main()
