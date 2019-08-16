#Reverse words in a line and print
word=list(input().split())
for i in word:
    print(i[::-1],end=" ")
print("")