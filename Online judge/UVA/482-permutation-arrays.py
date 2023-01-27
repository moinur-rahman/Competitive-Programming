from posixpath import split
import sys
from os import path
if(path.exists('input.txt')):
    sys.stdin = open('input.txt', 'r')
    sys.stdout = open('output.txt', 'w')


def solve():
    input()
    p = list(map(int, input().split()))
    a = list(map(str, input().split()))
    li = []
    for i in range(len(a)):
        li.append((p[i], a[i]))
    li.sort()

    ans = [x[1] for i, x in enumerate(li)]
    print(*ans, sep='\n')


q = 1
q = int(input())
for i in range(q):
    solve()
    if i != q - 1:
        print()