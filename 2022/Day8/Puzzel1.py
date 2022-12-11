class tree:
    def __init__( self, size ):
        self.size = size
        self.visible = False

input = []
with open("input.txt") as inputFile:
    for line in inputFile:
        line = line.strip()
        input.append( [] )
        for Character in line:
            input[-1].append( tree( int(Character) ) )

for y in range(len(input)):
    max = -1
    for x in range(len(input[y])):
        if input[y][x].size > max:
            input[y][x].visible = True
            max = input[y][x].size
    max = -1
    for x in range(len(input[y])):
        if input[y][len(input[y])-x-1].size > max:
            input[y][len(input[y])-x-1].visible = True
            max = input[y][len(input[y])-x-1].size
for x in range(len(input[0])):
    max = -1
    for y in range(len(input)):
        if input[y][x].size > max:
            input[y][x].visible = True
            max = input[y][x].size
    max = -1
    for y in range(len(input)):
        if input[len(input)-y-1][x].size > max:
            input[len(input)-y-1][x].visible = True
            max = input[len(input)-y-1][x].size

count = 0
for line in input:
    for tree in line:
        if tree.visible:
            count += 1
    
print(count)