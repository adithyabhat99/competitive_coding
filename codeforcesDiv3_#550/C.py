from collections import Counter
n = int(input())
a = sorted(list(map(int, input().split())))
for s in list(Counter(a).values()):
    if s > 2:
        print("NO")
        exit()
inc = []
dec = []
t = 0
for char in a:
    if t == 0:
        inc.append(char)
    else:
        dec.append(char)
    t = (t+1) % 2
inc = [str(i) for i in inc]
dec = [str(i) for i in dec]
print("YES")
print(len(inc))
print(' '.join(inc))
print(len(dec))
print(' '.join(dec[::-1]))
