'''
https://codeforces.com/problemset/submission/430/291826679
430A
2024/11/16 Y1
1600
'''
# ref
n, m = map(int, input().split())
a = list(map(int, input().split()))

st_range = sorted(range(n), key=lambda x: a[x])
ans = [0] * n
for i in range(0, n, 2):
    ans[st_range[i]] = 1

print(' '.join(map(str, ans)))