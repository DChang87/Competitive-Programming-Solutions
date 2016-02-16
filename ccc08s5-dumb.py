#nukit
n = int(input())
states = []
for zz in range(35):
    temp3 = []
    for z in range(35):
        temp2 = []
        for j in range(35):
            temp = []
            for k in range(35):
                temp.append(10)
            temp2.append(temp)
        temp3.append(temp2)
    states.append(temp3)
actions = [[2,1,0,2],[1,1,1,1],[0,0,2,1],[0,3,0,0],[1,0,0,1]]
#state stores the losing side
def move(state):
    flag = False
    if (states[state[0]][state[1]][state[2]][state[3]]!=10):
        return states[state[0]][state[1]][state[2]][state[3]];
    for i in range (5):
        if (state[0]>=actions[i][0] and state[1]>=actions[i][1] and state[2]>= actions[i][2] and state[3] >= actions[i][3]):
            if states[state[0]-actions[i][0]][state[1]-actions[i][1]][state[2]-actions[i][2]][state[3]-actions[i][3]]==10:
                boo = move([state[0]-actions[i][0], state[1]-actions[i][1],state[2]-actions[i][2],state[3]-actions[i][3]])
            else:
                boo = states[state[0]-actions[i][0]][state[1]-actions[i][1]][state[2]-actions[i][2]][state[3]-actions[i][3]]
            if (not boo):
                flag=True
                break
    states[state[0]][state[1]][state[2]][state[3]]=flag;
    return flag;
for i in range(n):
    A,B,C,D = input().split()
    A = int(A)
    B = int(B)
    C = int(C)
    D = int(D)
    if move([A,B,C,D]): 
        print("Patrick")
    else:
        print("Roland")
