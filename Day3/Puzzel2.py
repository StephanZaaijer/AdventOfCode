priority = 0;
input = []

with open("input.txt") as inputFile:
    for line in inputFile:
        input.append(line.strip())


for i in range(0, len(input), 3):
    elf1 = input[i]
    elf2 = input[i+1]
    elf3 = input[i+2]
    found = False;
    for itemElf1 in elf1:
        if found:
            break
        for itemElf2 in elf2:
            if found:
                break
            if itemElf1 == itemElf2 :
                for itemElf3 in elf3:
                    if found:
                        break
                    if itemElf3 == itemElf1:
                        found = True
                        if itemElf3 >= 'a' and itemElf3 <= 'z':
                            priority += ord(itemElf3)-ord('a')+1        
                        elif itemElf3 >= 'A' and itemElf3 <= 'Z':
                            priority += ord(itemElf3)-ord('A')+26+1            
                        else:
                            print( f"unexpected character found: {itemElf3}\n")

print( f"Priority = {priority}" )
