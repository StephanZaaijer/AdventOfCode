#include <iostream>
#include <fstream>
#include <string>

int main(){
    std::ifstream inputFile("input.txt");
    std::string temp;
    int max=0;
    int count = 0;
    while( std::getline(inputFile, temp) )
    {
        if ( temp == "" )            
        {
            if ( count > max )
                max = count;  
                count = 0;
        }
        else
          count += std::stoi(temp);
    }
    std::cout << "The maximum value = " <<  max << '\n';
}
