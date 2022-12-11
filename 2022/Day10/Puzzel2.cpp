#include <fstream>
#include <iostream>
#include <string>
#include "StringUtils.hpp"
#include <vector>

void crt( int cycle, const int &registerValue )
{
    int linePos = cycle%40;
    if( linePos == registerValue-1 | linePos == registerValue | linePos == registerValue+1 )
        std::cout << '#';
    else
        std::cout << '.';

    if( (cycle+1)%40==0 )
        std::cout << '\n';
}

int main()
{
    std::ifstream inputFile("input.txt");
    std::string temp;
    int registerValue = 1;
    int cycle = 0;
    while( std::getline( inputFile, temp ) )
    {
        std::vector<std::string> line = StringUtils::splitString( temp, ' ' );
        if( line[0] == "addx" )
        {
            for( unsigned int i = 0; i<2; i++ )
            {
                crt(cycle, registerValue);
                cycle++;
            }
            registerValue += std::stoi( line[1] );
        }
        else
        {
            crt(cycle, registerValue);
            cycle++;
        }    
    }
}