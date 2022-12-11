#include <string>
#include <fstream>
#include <vector>
#include <iostream>

struct tree
{
    int size;
    bool visible;

    tree( int size ):
        size( size ),
        visible( false )
    {}
};

int main()
{
    std::ifstream inputFile("input.txt");
    std::vector<std::vector<tree>> input = {};
    std::string temp;
    int row = 0;
    int amountOfTrees = 0;
    while( std::getline( inputFile, temp )  )
    {
        input.push_back( {} );
        for( char Character: temp )
        {
            input[row].push_back( tree( Character-'0' ) );
            amountOfTrees++;
        }
        row++;
    }
    for( int y=0; y<input.size(); y++ )
    {
        int max=-1;
        for( int x=0; x<input[y].size(); x++)
        {
            if( input[y][x].size > max )
            {
                input[y][x].visible = true;
                max = input[y][x].size;
            }
        }
        max=-1;
        for( int x=input[y].size(); x>0; x--)
        {
            if( input[y][x-1].size > max )
            {
                input[y][x-1].visible = true;
                max = input[y][x-1].size;
            }
        }
    }

    for( int y=0; y<input.size(); y++ )
    {
        int max=-1;
        for( int x=0; x<input[y].size(); x++)
        {
            if( input[x][y].size > max )
            {
                input[x][y].visible = true;
                max = input[x][y].size;
            }
        }
        max=-1;
        for( int x=input[y].size(); x>0; x--)
        {
            if( input[x-1][y].size > max )
            {
                input[x-1][y].visible = true;
                max = input[x-1][y].size;
            }
        }
    }

    int count = 0;
    for( auto line: input )
    {
        for( auto tree: line)
        {
            if( tree.visible )
                count++;
        }
    }
    std::cout << count << '\n';
}