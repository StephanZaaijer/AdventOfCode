#include <fstream>
#include <iostream>
#include <string>
#include "StringUtils.hpp"
#include <vector>

int main()
{
    std::ifstream inputFile("input.txt");
    std::string temp;
    int registerValue = 1;
    int cycle = 0;
    int total = 0;
    while( std::getline( inputFile, temp ) )
    {
        std::vector<std::string> line = StringUtils::splitString( temp, ' ' );
        if( line[0] == "addx" )
        {
            for( unsigned int i = 0; i<2; i++ )
            {
                cycle++;
                if( ( cycle - 20 ) % 40 == 0)
                {
                    std::cout << "Cycle: " << cycle << " Register value: " << registerValue << '\n';
                    total += cycle * registerValue;
                }
            }
            registerValue += std::stoi( line[1] );
        }
        else
        {
            cycle++;
            if( ( cycle - 20 ) % 40 == 0)
            {
                std::cout << "Cycle: " << cycle << " Register value: " << registerValue << '\n';
                total += cycle * registerValue;
            }
        }    
    }
    std::cout << "Total: " << total << '\n';
}