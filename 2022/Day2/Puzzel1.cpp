#include <iostream>
#include <fstream>
#include <string>

int main(){
    std::ifstream inputFile("input.txt");
    std::string temp;
    int score = 0;
    while( std::getline(inputFile, temp) )
    {

        char player1 = temp[0];
        char player2 = temp[2];

        if( player2 == 'X')
            score+=1;
        else if( player2 == 'Y')
            score+=2;
        else if( player2 == 'Z')
            score+=3;
        else
            std::cerr << "Unknown character found: " << player2 << '\n';

        if( player1 == 'A' && player2 == 'X')
            score+=3;
        else if ( player1 == 'B' && player2 == 'Y')
            score+=3;
        else if ( player1 == 'C' && player2 == 'Z')
            score+=3;
        
        else if( player1 == 'C' && player2 == 'X')
            score+=6;
        else if( player1 == 'A' && player2 == 'Z')
            continue;        
        else if( player1 == 'B' && player2 == 'Z')
            score+=6;
        else if( player1 == 'C' && player2 == 'Y')
            continue;
        
        else if( player1 == 'A' && player2 == 'Y')
            score+=6;
        else if( player1 == 'B' && player2 == 'X')
            continue;
        else
            std::cerr << "Unknown combination 1: " << player1 << ", 2: " << player2 << '\n';
    }
    std::cout << "Score: " << score << "\n";
}
