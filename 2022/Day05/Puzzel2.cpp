#include <iostream>
#include <vector>
#include <string>
#include <vector>
#include <fstream>
#include "algorithm"

class Stack
{
private:
  std::vector<char> items;

public:
  Stack()
  {
    items = {};
  }
  Stack( const std::string &input )
  {
    items = {};
    add( input );
  }
  void add( const std::string& input)
  {
    for( char item: input )
    {
        items.push_back(item);
    }
  }
  std::string pop( int amount )
  {
    std::string temp;
    for( unsigned int i=0; i< amount; i++)
    {
        temp+=items[items.size()-1];
        items.pop_back();
    }
    std::reverse( temp.begin(), temp.end() );
    return temp;
  }
};

// [J]             [F] [M]            
// [Z] [F]     [G] [Q] [F]            
// [G] [P]     [H] [Z] [S] [Q]        
// [V] [W] [Z] [P] [D] [G] [P]        
// [T] [D] [S] [Z] [N] [W] [B] [N]    
// [D] [M] [R] [J] [J] [P] [V] [P] [J]
// [B] [R] [C] [T] [C] [V] [C] [B] [P]
// [N] [S] [V] [R] [T] [N] [G] [Z] [W]
//  1   2   3   4   5   6   7   8   9 

int main()
{
    std::vector<std::string> input = {};
    std::ifstream inputFile("input.txt");
    std::string temp;
    while( std::getline(inputFile, temp))
        input.push_back( temp );
    
    Stack stack1( "NBDTVGZJ" );
    Stack stack2( "SRMDWPF" );
    Stack stack3( "VCRSZ" );
    Stack stack4( "RTJZPHG" );
    Stack stack5( "TCJNDZQF" );
    Stack stack6( "NVPWGSFM" );
    Stack stack7( "GCVBPQ" );
    Stack stack8( "ZBPN" );
    Stack stack9( "WPJ" );

        
    std::vector<Stack*> stackList = {&stack1, &stack2, &stack3, &stack4, &stack5, &stack6, &stack7, &stack8, &stack9};

    Stack* sourceStack = NULL;
    Stack* destinationStack = NULL;
    for( auto line: input )
    {
        //remove move
        line = line.substr( line.find(' ')+1, line.size()-line.find(' ') );
        int amount = std::stoi( line.substr(0, line.find(' ') ) );
        //remove amount
        line = line.substr( line.find( ' ' )+1, line.size()-line.find(' ') );    
        //remove from
        line = line.substr( line.find( ' ' )+1, line.size()-line.find(' ') );
        int source = std::stoi( line.substr(0, line.find(' ') ) );
        //remove source
        line = line.substr( line.find( ' ' )+1, line.size()-line.find(' ') );    
        //remove to
        line = line.substr( line.find( ' ' )+1, line.size()-line.find(' ') );
        int destination = std::stoi( line.substr(0, line.find(' ') ) );

        sourceStack = stackList[source-1];
        destinationStack = stackList[destination-1];
        
        destinationStack->add( sourceStack->pop( amount ) );
    }
    for( auto stack: stackList){
        std::cout << stack->pop( 1 );
    }
    
}