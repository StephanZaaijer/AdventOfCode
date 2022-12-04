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
    for(int lineIndex = 0; lineIndex<input.size(); lineIndex+=3)
    {
        bool found = false;
        for( int x=0; x<input[lineIndex].size()&&!found; x++){
            char elf1 = input[lineIndex][x];
            for( int y=0; y<input[lineIndex+1].size()&&!found; y++){
                char elf2 = input[lineIndex+1][y];
                if (elf1 == elf2)
                {
                    for( auto elf3: input[lineIndex+2])
                    {
                        if (elf2 == elf3)
                        {
                            if (elf3 >= 'a' && elf3 <= 'z')
                            {
                                priority+=elf3-'a'+1;
                                found = true;
                                break;
                            }
                            else if(elf3 >= 'A' && elf3 <= 'Z')
                            {
                                priority+=elf3-'A'+26+1;
                                found = true;
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
    std::cout << "Priority = " << priority << '\n';
}