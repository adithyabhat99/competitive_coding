from datetime import date
Week={
    'Mon':0,
    'Tue':1,
    'Wed':2,
    'Thu':3,
    'Fri':4,
    'Sat':5,
    'Sun':6
}
d,day=input().split()
d=d.split('-')
d=[int(i) for i in d]

birthday=input().split('-')
birthday=[int(i) for i in birthday]

d1=date(d[0],d[1],d[2])
d2=date(d[0],birthday[0],birthday[1])

if d1>d2:
    d2=date(d[0]+1,birthday[0],birthday[1])

#print(d1)
#print(d2)
ordinal1=d1.toordinal()
ordinal2=d2.toordinal()

c=0
for d_ord in range(ordinal1,ordinal2+1):
    D=date.fromordinal(d_ord)
    if D.weekday()==Week[day]:
        c+=1

print(c)