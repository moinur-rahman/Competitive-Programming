import sys
from os import path
if (path.exists('input.txt')):
    sys.stdin = open('input.txt', 'r')
    sys.stdout = open('output.txt', 'w')


def solve():
    while (1):
        try:
            line = input()
            line = list(map(int, line.split()))
            # print(line)
            line.pop(-1)

            mx = -sys.maxsize

            for i in range(len(line)):
                prod = 1
                for j in range(i, len(line)):
                    prod *= line[j]
                    # print(prod)
                    mx = max(mx, prod)
            print(mx)
        except EOFError:
            break


q = 1
# q = int(input())
for i in range(q):
    solve()
