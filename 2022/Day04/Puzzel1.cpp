#include <fstream>
#include <string>
#include <vector>
#include <iostream>

int main()
{
  std::vector<std::string> input = {};
  std::ifstream inputFile("input.txt");
  std::string temp;
  while( std::getline(inputFile, temp) )
  {
    input.push_back(temp);
  }
  int counter = 0;
  for( auto item: input )
  {
    std::string elf1 = item.substr( 0, item.find(',') );
    std::string elf2 = item.substr( item.find(',')+1, item.size()-item.find(',') );

    int beginElf1 = std::stoi( elf1.substr( 0, elf1.find('-') ) );
    int endElf1 = std::stoi( elf1.substr( elf1.find('-')+1, elf1.size()-elf1.find('-') ) );

    int beginElf2 = std::stoi( elf2.substr( 0, elf2.find('-') ) );
    int endElf2 = std::stoi( elf2.substr( elf2.find('-')+1,  elf2.size()-elf2.find('-') ) );


    if( beginElf1 >= beginElf2 && endElf1 <= endElf2 )
      counter++;
    else if( beginElf2 >= beginElf1 && endElf2 <= endElf1 )
      counter++;
  }
  std::cout << counter << '\n';
}