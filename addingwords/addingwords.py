
import sys

# kind of from https://github.com/JonSteinn/Kattis-Solutions/blob/master/src/Adding%20Words/Python%203/addingwords.py
# not editing it because this gave me a headache
key_map = {}
value_map = {}
for n in sys.stdin:
    tokens = n.split()
    if tokens[0] == 'def':
        key_map[tokens[1]] = tokens[2]
        value_map[tokens[2]] = tokens[1]
    elif tokens[0] == 'calc':
        if len(list(filter(lambda z: z in key_map.keys(), tokens[1:][::2]))) != len(tokens[1:][::2]):
            print(" ".join(tokens[1:]), 'unknown')
        else:
            val = str(eval(" ".join(map(lambda z: key_map[z] if z in key_map.keys() else z, tokens[1:-1]))))
            if val in value_map.keys():
                print(" ".join(tokens[1:]), value_map[val])
            else:
                print(" ".join(tokens[1:]), 'unknown')
    else:
        key_map.clear()
        value_map.clear()


# import sys

# def main():
#     key_map = dict()
#     value_map = dict()
#     # while n != "clear":
#     for n in sys.stdin:
#         tokens = n.split()
#         status = ''
#         if tokens[0] == "def":
#             if tokens[1] in key_map.keys():
#                 del value_map[int(key_map[tokens[1]])]
#             key_map[tokens[1]] = tokens[2]
#             value_map[int(tokens[2])] = tokens[1]
#         elif tokens[0] == "calc":
#             if len(list(filter(lambda z: z in key_map.keys(), tokens[1:][::2]))) != len(tokens[1:][::2]):
#                 print(" ".join(tokens[1:]), 'unknown')
#             else:
#                 val = str(eval(" ".join(map(lambda z: key_map[z] if z in key_map.keys() else z, tokens[1:-1]))))
#                 if val in value_map.keys():
#                     print(" ".join (tokens[1:]), value_map[val])
#                 else:
#                     print(" ".join (tokens[1:]), 'unknown')
#         else:
#             key_map.clear()
#             value_map.clear()
#             # calc
#             # eval_tokens = []
#             # for i in range(1, len(tokens)-1):
#             #     if tokens[i] == '+' or tokens[i] == '-': 
#             #         eval_tokens.append(tokens[i])
#             #     else:
#             #         if not (tokens[i] in key_map.keys()):
#             #             status = 'unknown'
#             #             # print(tokens[i])
#             #             break
#             #         else:
#             #             eval_tokens.append(key_map[tokens[i]])

#             # if status != 'unknown':
#             #     # calculate
#             #     result = str(eval(' '.join(eval_tokens)))
#             #     # print(''.join(eval_tokens), result, type(result))

#             #     if result in value_map.keys():
#             #         status = value_map[result]
#             #     else:
#             #         status = 'unknown'

#             # print(' '.join(tokens[1:]), status)

#     return

# if __name__ == "__main__":
#     main()

