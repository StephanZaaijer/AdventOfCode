priority = 0;
input = []

with open("input.txt") as inputFile:
    for line in inputFile:
        input.append(line.strip())


for line in input:
    alreadyFound=""
    for i in range(0, int(len(line)/2)):
        currentChar = line[i]
        for j in range(int(len(line)/2), len(line)):
            if currentChar == line[j]:
                if currentChar not in alreadyFound:
                    alreadyFound += currentChar
                    if currentChar >= 'a' and currentChar <= 'z':
                        priority += ord(currentChar)-ord('a')+1        
                    elif currentChar >= 'A' and currentChar <= 'Z':
                        priority += ord(currentChar)-ord('A')+26+1            
                    else:
                        print( f"unexpected character found: {currentChar}\n")

print( f"Priority = {priority}" )
