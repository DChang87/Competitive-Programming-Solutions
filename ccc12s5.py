r,c = input().split()
r=int(r)
c=int(c)
n = int(input())
cats = []
for i in range(n):
    a,b = input().split()
    a=int(a)
    b=int(b)
    cats.append([a-1,b-1])
paths = []
for i in range(r):
    temp = []
    for k in range(c):
        temp.append(0)
    paths.append(temp)
paths[0][0]=1
for i in range(r):
    for k in range(c):
        if i-1>=0 and [i-1,k] not in cats and [i,k] not in cats:
            paths[i][k]+=paths[i-1][k]
        if k-1>=0 and [i,k-1] not in cats and [i,k] not in cats:
            paths[i][k]+=paths[i][k-1]
print(paths[-1][-1])
