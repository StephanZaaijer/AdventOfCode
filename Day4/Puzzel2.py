counter=0
with open('input.txt') as inputFile:
    for line in inputFile:
        elf1 = line.split(',')[0]
        elf2 = line.split(',')[1]

        elf1begin = int(elf1.split('-')[0])
        elf1end = int(elf1.split('-')[1])

        elf2begin = int(elf2.split('-')[0])
        elf2end = int(elf2.split('-')[1])

        if( elf1begin >= elf2begin and elf1begin <= elf2end ):
            counter+=1
        elif( elf1end >= elf2begin and elf1end <= elf2end ):
            counter+=1
        elif( elf2begin >= elf1begin and elf2begin <= elf1end ):
            counter+=1
        elif( elf2end >= elf1begin and elf2end <= elf1end ):
            counter+=1

print( f"{counter=}" )
