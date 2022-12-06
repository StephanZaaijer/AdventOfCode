with open("input.txt") as inputFile:
    input = inputFile.read()

AmountOfUniqueCharacters = 4

for i in range( len(input)-AmountOfUniqueCharacters ):
    unique = True
    temp = input[i:i+AmountOfUniqueCharacters]
    for j in temp:
        if temp.count(j) != 1:
            unique = False
            break
    if unique:
        print( i + AmountOfUniqueCharacters )
        break
    