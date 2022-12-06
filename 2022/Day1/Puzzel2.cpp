#include <iostream>
#include <fstream>
#include <string>
#include <vector> 
#include <algorithm>

int main(){
    std::ifstream inputFile("input.txt");
    std::string temp;
    std::vector<int> input={};
    int count = 0;
    while( std::getline(inputFile, temp) )
    {
        if ( temp == "" )            
        {
            input.push_back(count);  
            count = 0;
        }
        else
          count += std::stoi(temp);
    }
    std::sort(input.begin(), input.end());
    std::cout << "The maximum value = " <<  input[input.size()-1] << '\n';
    std::cout << "The sum of top 3 value = " <<  input[input.size()-1] + input[input.size()-2] + input[input.size()-3] << '\n';
    
}
