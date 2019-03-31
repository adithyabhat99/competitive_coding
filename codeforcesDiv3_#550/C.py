#Wrong answer !

from collections import Counter
n=int(input())
l=input().split()
count=Counter(l)
c=1
for i in count.values():
    if int(i)>2:
        print("NO")
        c=0
        break
if c==1:
    x=0
    inc=[]
    dec=[]
    print("YES")
    l.sort()
    while x<len(l) and x+1<len(l):
        if l[x]!=l[x+1]:
            inc.append(l[x])
            x+=1
        else:
            inc.append(l[x])
            dec.append(l[x+1])
            x+=2
    print(len(inc))
    inc=[int(i) for i in inc]
    for i in inc:
        print(i,end=" ")
    print(len(dec))
    dec = [int(i) for i in dec][::-1]
    dec.reverse()
    for i in dec:
        print(i,end=" ")
    print("")
    
    
    



