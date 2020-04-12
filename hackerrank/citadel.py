n=int(input())
l=input().split()
l=[int(i) for i in l]
l1=[i for i in l]
i=0
while i<n and i+3<len(l) and l[i]!=69:
    t1=l[i+1]
    t2=l[i+2]
    t3=l[i+3]
    if l[i]==6:
        l1[t3]=l1[t1]+l1[t2]
        
    elif l[i]==9:
        l1[t3]=l1[t1]*l1[t2]
    
    i+=4
    
for i in l1:
    print(i,end=' ')
print()