import sys
from os import path
if(path.exists('input.txt')):
    sys.stdin = open('input.txt', 'r')
    sys.stdout = open('output.txt', 'w')


def solve():
    cnt = 0
    while True:
        cnt += 1

        n = int(input())

        if n == 0:
            return
        a = list(map(int, input().split()))

        res = sum(a)//n
        ans = 0
        for i in range(n):
            ans += max(0, a[i] - res)

        print("Set #" + str(cnt))
        print("The minimum number of moves is " + str(int(ans)) + ".")
        print()


q = 1
#q = int(input())
for i in range(q):
    solve()
