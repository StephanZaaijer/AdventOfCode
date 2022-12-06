#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main()
{
    std::ifstream inputFile("input.txt");
    std::vector<std::string> input = {};
    std::string temp;
    int priority = 0;
    while( std::getline(inputFile, temp))
    {
        input.push_back(temp);
    }
    for(auto line: input )
    {
        std::string alreadyFound="";
        for( int i=0; i<line.size()/2; i++)
        {
            char currentChar = line[i];
            for(unsigned int x=line.size()/2; x < line.size(); x++)
            {
                if( currentChar == line[x])
                {
                    bool found=false;
                    for( unsigned int y=0; y<alreadyFound.size()&&!found; y++)
                    {
                        if( currentChar==alreadyFound[y] )
                        {
                            found = true;
                            break;
                        }
                    }
                    if( !found )
                    {
                        alreadyFound += currentChar;
                        if (currentChar >= 'a' && currentChar <= 'z')
                            priority+=currentChar-'a'+1;
                        else if(currentChar >= 'A' && currentChar <= 'Z')
                            priority+=currentChar-'A'+26+1;
                        else
                            std::cerr<<"unexpected character found: " << currentChar << '\n';
                    }
                }   
            }
        }
    }
    std::cout << "Priority = " << priority << '\n';
}