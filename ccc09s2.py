"""
For your birthday, you have been given a grid of R (1 < R < 30) rows of lights, with each row containing L (1 ≤ L < 8) lights. 
Lights can be in one of two states: on or off. For this question, the topmost row is row R, and the bottom-most row is row 1. 
Also, beside all rows except the topmost row (row R), there is a button which can be pushed.
Pushing the button beside row k (1 ≤ k < R) will peform an "exclusive-or" operation on each light of row k, which is described 
below. Consider column i in row k, where 1 ≤ i ≤ L. If the lights in column i of row k and column i of row k + 1 are both the 
same (i.e., both on, or both off), then pushing the button beside row k will cause the light in column i of row k to be off. 
If the lights in column i of row k and column i of row k + 1 are different (i.e., one is on, and the other is off), then pushing 
the button beside row k will cause the light in column i of row k to be on. An example is shown below, for L = 4:
Column Numbers	1	2	3	4
Row k+1	on	on	off	off
Row k before button pushed	on	off	on	off
Row k after button pushed	off	on	on	off
You are told which lights are initially on and which are initially off. You must calculate how many different light patterns are possible for the bottom row by any sequence of button pushes. Each button may only be pressed once, but in any order.
"""
R = int(input())
L = int(input())
lights = []
for i in range(R):
    temp = input().split()
    temp2 = []
    for j in temp:
        temp2.append(int(j))
    lights.append(temp2)
prev = [lights[0]]
for i in range(1,R):
    newprev = [lights[i]]
    cur = lights[i]
    for j in prev:
        newLights = []
        for k in range(L):
            newLights.append((cur[k]+j[k])%2)
        if newLights not in newprev:
            newprev.append(newLights)
    prev = newprev[::]
print(len(prev))
