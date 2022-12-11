#include <iostream>
#include <fstream>
#include <string>

int main(){
    std::ifstream inputFile("input.txt");
    std::string temp;
    int score = 0;
    while( std::getline(inputFile, temp) )
    {
        int round = 0;

        char player1 = temp[0];
        char player2 = temp[2];

        if( player2 == 'X')             //Lose
            round+=0;
        else if( player2 == 'Y')        //Draw
            round+=3;
        else if( player2 == 'Z')        //Win
            round+=6;
        else
            std::cerr << "Unknown character found: " << player2 << '\n';

        if( player1 == 'A' && player2 == 'X')
            round+=3;
        else if( player1 == 'A' && player2 == 'Y')
            round+=1;
        else if( player1 == 'A' && player2 == 'Z')
            round+=2;
        
        else if( player1 == 'B' && player2 == 'X')
            round+=1;
        else if( player1 == 'B' && player2 == 'Y')
            round+=2;
        else if( player1 == 'B' && player2 == 'Z')
            round+=3;
        
        else if( player1 == 'C' && player2 == 'X')
            round+=2;
        else if( player1 == 'C' && player2 == 'Y')
            round+=3;
        else if( player1 == 'C' && player2 == 'Z')
            round+=1;
        else
            std::cerr << "Unknown combination 1: " << player1 << ", 2: " << player2 << '\n';
        


        score += round;    
    }
    std::cout << "Score: " << score << "\n";
}
