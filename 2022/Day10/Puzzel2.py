def crt( cycle, registerValue ):
    linePos = cycle%40
    if( linePos == registerValue-1 or linePos == registerValue or linePos == registerValue+1 ):
        print('#', end='')
    else:
        print('.', end='')
    if( (cycle+1)%40==0 ):
        print('')

input = []
with open("input.txt", "r") as inputFile:
    input = inputFile.readlines()

registerValue = 1
cycle = 0

for line in input:
    line = line.split(" ")
    if( line[0] == "addx" ):
        for i in range(2):
            crt( cycle, registerValue )
            cycle += 1
        registerValue += int(line[1])
    else:
        crt( cycle, registerValue )
        cycle += 1