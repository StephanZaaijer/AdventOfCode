#include <fstream>
#include <vector>
#include <string>
#include <iostream>

#include "StringUtils.hpp"

struct Coordinate
{
    int x=0;
    int y=0;

    bool operator==(const Coordinate & rhs ) const
    {
        return x == rhs.x && y == rhs.y;
    }

    friend std::ostream& operator<<(std::ostream& stream, const Coordinate &rhs)
    {
        stream << "X: " << rhs.x << " Y: " << rhs.y;
        return stream;
    }

};

class Set
{
public:
    Set(){}

    bool Contains( const Coordinate& containsItem )
    {
        for( const Coordinate & item: items )
        {
            if( item == containsItem )
                return true;
        }
        return false;
    }

    void Add( const Coordinate& newItem )
    {
        if( !Contains( newItem ) )
            items.push_back( newItem );
    }

    unsigned int size() const
    {
        return items.size();
    }

    friend std::ostream& operator<<(std::ostream& stream, const Set &rhs)
    {
        for( auto item: rhs.items )
            stream << item << '\n';
        return stream;
    }
private:
    std::vector<Coordinate> items = {};
};

bool touching( const Coordinate &Head, const Coordinate &Tail )
{
    if( Head.x == Tail.x && Head.y == Tail.y )
        return true;
    
    if( abs( Head.x - Tail.x ) == 1 && Head.y == Tail.y )
        return true;
    
    if( abs( Head.y - Tail.y ) == 1 && Head.x == Tail.x )
        return true;

    if( abs( Head.x - Tail.x ) == 1 && abs( Head.y - Tail.y ) == 1 )
        return true;
    
    return false;
}

int main()
{
    std::ifstream inputFile("input.txt");
    std::vector<std::string> input = {};
    std::string temp;
    while( std::getline( inputFile, temp ) )
        input.push_back( temp );

    Coordinate Head = {0, 0};
    Coordinate Tail = {0, 0};
    Set tailLocations;
    tailLocations.Add(Tail);
    for( auto line: input)
    {
        std::vector<std::string> data = StringUtils::splitString( line, ' ' );
        for( int i = 0; i<std::stoi( data[1]); i++ )
        {
            if( data[0]== "U" )
                Head.y++;
            else if( data[0]== "R" )
                Head.x++;
            else if( data[0]== "D" )
                Head.y--;
            else if( data[0]== "L" )
                Head.x--;
            if( !touching( Head, Tail ) )
            {
                if( abs( Head.x - Tail.x ) == 2 && abs( Head.y - Tail.y ) == 2 )
                {
                    if( Head.x > Tail.x )
                        Tail.x++;
                    else
                        Tail.x--;
                    if( Head.y > Tail.y )
                        Tail.y++;
                    else
                        Tail.y--;
                }

                else if( abs( Head.x - Tail.x ) == 2 && Head.y == Tail.y )
                {
                    if( Head.x > Tail.x )
                        Tail.x++;
                    else
                        Tail.x--;
                }
                else if( Head.x == Tail.x && abs( Head.y - Tail.y ) == 2 )
                {
                    if( Head.y > Tail.y )
                        Tail.y++;
                    else
                        Tail.y--;
                }
                else
                {
                    if( Head.x > Tail.x )
                        Tail.x++;
                    else
                        Tail.x--;
                    if( Head.y > Tail.y )
                        Tail.y++;
                    else
                        Tail.y--;
                }   
            } 
            tailLocations.Add(Tail);
        }  
    }
    std::cout << "Tail locations = " << tailLocations.size();

}

