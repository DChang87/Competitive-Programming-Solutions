n,m = input().split()
n = int(n)
m = int(m)
cities = {}
invCities = {}
connections = []
for i in range(n):
    a,b = input().split()
    if a not in cities:
        cities[a]=len(cities)
        invCities[len(cities)-1]=a
        connections.append([])
    if b not in cities:
        cities[b] = len(cities)
        invCities[len(cities)-1]=b
        connections.append([])
    connections[cities[a]].append(cities[b])
    connections[cities[b]].append(cities[a])
def iterate(start,end,sofar):
    global connections,currentMin,currentStr
    sofar+=start[0].upper()
    if start==end:
        if len(sofar)<currentMin:
            currentStr = sofar
        return
    for i in range(len(connections[cities[start]])):
        if invCities[connections[cities[start]][i]][0].upper() not in sofar:
            iterate(invCities[connections[cities[start]][i]],end,sofar)

for i in range(m):
    a,b = input().split()
    currentMin = 10000000000
    currentStr=""
    iterate(a,b,"")
    print(currentStr)
