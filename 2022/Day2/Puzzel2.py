input = []
with open('input.txt') as file:
    for line in file:
        input.append(line)

score = 0
for game in input:
    player1 = game[0];
    player2 = game[2];
    if player2 == 'X':
        pass
    elif player2 == 'Y':
        score+=3
    elif player2 == 'Z':
        score+=6
    else:
        print(f"Unknown character found: {player2=}")

    
    if(player1 == 'A' and player2 == 'X'):
        score+=3
    elif(player1 == 'A' and player2 == 'Y'):
        score+=1
    elif(player1 == 'A' and player2 == 'Z'):
        score+=2
    
    elif(player1 == 'B' and player2 == 'X'):
        score+=1
    elif(player1 == 'B' and player2 == 'Y'):
        score+=2
    elif(player1 == 'B' and player2 == 'Z'):
        score+=3
    
    elif(player1 == 'C' and player2 == 'X'):
        score+=2
    elif(player1 == 'C' and player2 == 'Y'):
        score+=3
    elif(player1 == 'C' and player2 == 'Z'):
        score+=1
    
    else:
        print(f"Unknown combination: {player1=}, {player2=}")
print(f"Score: {score}\n")


