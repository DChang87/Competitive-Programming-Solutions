"""
You are a mouse that lives in a cage in a large laboratory. The laboratory is composed of one 
rectangular grid of square cages, with a total of R rows and C columns of cages.
To get your exercise, the laboratory owners allow you to move between cages. You can move between cages 
either by moving right between two adjacent cages in the same row, or by moving down between two adjacent 
cages in the same column. You cannot move diagonally, left or up.
Your cage is in one corner of the laboratory, which has the label (1,1) (to indicate top-most row, left-most column). 
You would like to visit your brother who lives in the cage labelled (R,C) (bottom-most row, right-most column),
which is in the other corner diagonally. However, there are some cages which you cannot pass through, since they contain cats.
Your brother, who loves numbers, would like to know how many different paths there are between your cage and his that do 
not pass through any cat cage. Write a program to compute this number of cat-free paths.
Input Format
The first line of input contains two integers R and C (1 ≤ R, C ≤ 25), separated by one space representing the number of 
rows and columns (respectively). On the second line of input is the integer K, the number of cages that contain cats. 
The next K lines each contain the row and column positions (in that order) for a cage that contains a cat. None of the 
K cat cages are repeated, and all cages are valid positions. Note that (1,1) and (R,C) will not be cat cages.
Output Format
Output the non-negative integer value representing the number of paths between your cat cage at position (1,1) and 
your brother's cage at position (R,C). You can assume the output will be strictly less than 109.
"""
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
