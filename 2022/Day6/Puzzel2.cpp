#include <iostream>
#include <fstream>
#include <vector>
#include <string> 
#include <algorithm>

int main()
{
    std::ifstream inputFile("input.txt");
    std::string temp = "";
    std::vector<char> input;
    
    std::getline(inputFile, temp);
    for( auto character: temp )
        input.push_back( character );
    
    for( unsigned int item=0; item<input.size()-14; item++)
    {
        std::string temp = "";
        bool unique = true;
        for( int i=0; i<14; i++ )
            temp += input[item+i];


        for( char character: temp )
        {
            int count = std::count( temp.begin(), temp.end(), character );
            if( count != 1 )
            {
                unique = false;
                break;
            }

        }
        if( unique )
        {
            std::cout << item+14;
            break;
        }
    }
}