#include <fstream>
#include <vector>
#include <string>
#include <iostream>

#include "StringUtils.hpp"

struct Coordinate
{
    int x=0;
    int y=0;

    Coordinate( const int &x, const int &y):
        x(x),
        y(y)
    {}

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

    std::vector<Coordinate*> snake = {  new Coordinate( 0, 0 ),
                                        new Coordinate( 0, 0 ),
                                        new Coordinate( 0, 0 ),
                                        new Coordinate( 0, 0 ),
                                        new Coordinate( 0, 0 ),
                                        new Coordinate( 0, 0 ),
                                        new Coordinate( 0, 0 ),
                                        new Coordinate( 0, 0 ),
                                        new Coordinate( 0, 0 ),
                                        new Coordinate( 0, 0 ) };
    Set tailLocations;
    
    Coordinate* Head = snake[0];
    Coordinate* Tail = snake[9];
    
    tailLocations.Add(*Tail);

    for( auto line: input)
    {
        std::vector<std::string> data = StringUtils::splitString( line, ' ' );
        for( int i = 0; i<std::stoi( data[1]); i++ )
        {
            if( data[0]== "U" )
                Head -> y++;
            else if( data[0]== "R" )
                Head -> x++;
            else if( data[0]== "D" )
                Head -> y--;
            else if( data[0]== "L" )
                Head -> x--;
            for( unsigned int j = 0; j < snake.size()-1; j++ )
            {
                Coordinate *snakebody1 = snake[j];
                Coordinate *snakebody2 = snake[j+1];
                if( !touching( *snakebody1, *snakebody2 ) )
                {
                    if( abs( snakebody1->x - snakebody2->x ) == 2 && abs( snakebody1->y - snakebody2->y ) == 2 )
                {
                    if( snakebody1->x > snakebody2->x )
                        snakebody2->x++;
                    else
                        snakebody2->x--;
                    if( snakebody1->y > snakebody2->y )
                        snakebody2->y++;
                    else
                        snakebody2->y--;
                }

                else if( abs( snakebody1->x - snakebody2->x ) == 2 && snakebody1->y == snakebody2->y )
                {
                    if( snakebody1->x > snakebody2->x )
                        snakebody2->x++;
                    else
                        snakebody2->x--;
                }
                else if( snakebody1->x == snakebody2->x && abs( snakebody1->y - snakebody2->y ) == 2 )
                {
                    if( snakebody1->y > snakebody2->y )
                        snakebody2->y++;
                    else
                        snakebody2->y--;
                }
                else
                {
                    if( snakebody1->x > snakebody2->x )
                        snakebody2->x++;
                    else
                        snakebody2->x--;
                    if( snakebody1->y > snakebody2->y )
                        snakebody2->y++;
                    else
                        snakebody2->y--;
                }   
                } 
            }
            tailLocations.Add(*Tail);
        }  
    }
    std::cout << "Tail locations = " << tailLocations.size();

}

