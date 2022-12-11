input = []
with open("input.txt", "r") as inputFile:
    input = inputFile.readlines()

registerValue = 1
cycle = 0
total = 0
    
for line in input:
    line = line.split(" ")
    if( line[0] == "addx" ):
        for i in range(2):
            cycle += 1
            if( ( cycle - 20 ) % 40 == 0):
                print("Cycle: " + str(cycle) + " Register value: " + str(registerValue))
                total += cycle * registerValue
        registerValue += int(line[1])
    else:
        cycle += 1
        if( ( cycle - 20 ) % 40 == 0):
                print("Cycle: " + str(cycle) + " Register value: " + str(registerValue))
                total += cycle * registerValue

print(f"Total: {total}\n")
