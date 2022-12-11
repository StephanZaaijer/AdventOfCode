#include <functional>
#include <vector>
#include <iostream>
#include <algorithm>

// #define TEST

class Monkey
{
public:
    Monkey( std::function<unsigned long long(unsigned long long)> operation, unsigned long long divider, unsigned long long indexTrue, unsigned long long indexFalse, std::vector<unsigned long long> startItems={} ):
        operation( operation ),
        divider( divider ),
        indexTrue( indexTrue ),
        indexFalse( indexFalse ),
        items( startItems ),
        inspections( 0 )
    {}

    void execute( std::vector<Monkey*> monkeys )
    {
        for( auto worryLevel: items )
        {
            worryLevel = operation( worryLevel );
            #ifdef TEST
            worryLevel %= 96577; // 23 * 19 * 13 * 17
            #else
            worryLevel%=9699690; // 13 * 3 * 7 * 2 * 19 * 5 * 11 * 17 = 9699690
            #endif //TEST
            inspections++;

            if( worryLevel % divider == 0 )
                monkeys[indexTrue]->add(worryLevel);
            else
                monkeys[indexFalse]->add(worryLevel);
        }
        items = {};
    }

    void add( unsigned long long worryLevel )
    {
        items.push_back( worryLevel );
    }

    unsigned long long getTotalInspections() const
    {
        return inspections;
    }

private:
    std::function<unsigned long long(unsigned long long)> operation;
    unsigned long long divider;
    unsigned long long indexTrue;
    unsigned long long indexFalse;
    unsigned long long inspections;
    std::vector<unsigned long long> items = {};

};

   

int main()
{

    std::vector<Monkey*> monkeys = {};

    #ifdef TEST        
    // Example monkeys
    monkeys.push_back( new Monkey( []( unsigned long long worryLevel ){ return worryLevel * 19; }, 23, 2, 3, { 79, 98 } ) );
    monkeys.push_back( new Monkey( []( unsigned long long worryLevel ){ return worryLevel + 6; }, 19, 2, 0, { 54, 65, 75, 74 } ) );
    monkeys.push_back( new Monkey( []( unsigned long long worryLevel ){ return worryLevel*worryLevel; }, 13, 1, 3, { 79, 60, 97 } ) );
    monkeys.push_back( new Monkey( []( unsigned long long worryLevel ){ return worryLevel + 3; }, 17, 0, 1, { 74 } ) );
    #else
    monkeys.push_back( new Monkey( []( unsigned long long worryLevel ){ return worryLevel * 3; }, 13, 6, 2, { 89, 73, 66, 57, 64, 80 } ) );
    monkeys.push_back( new Monkey( []( unsigned long long worryLevel ){ return worryLevel + 1; }, 3, 7, 4, { 83, 78, 81, 55, 81, 59, 69 } ) );
    monkeys.push_back( new Monkey( []( unsigned long long worryLevel ){ return worryLevel * 13; }, 7, 1, 4, { 76, 91, 58, 85 } ) );
    monkeys.push_back( new Monkey( []( unsigned long long worryLevel ){ return worryLevel * worryLevel; }, 2, 6, 0, { 71, 72, 74, 76, 68 } ) );
    monkeys.push_back( new Monkey( []( unsigned long long worryLevel ){ return worryLevel + 7; }, 19, 5, 7, { 98, 85, 84 } ) );
    monkeys.push_back( new Monkey( []( unsigned long long worryLevel ){ return worryLevel + 8; }, 5, 3, 0, { 78 } ) );
    monkeys.push_back( new Monkey( []( unsigned long long worryLevel ){ return worryLevel + 4; }, 11, 1, 2, { 86, 70, 60, 88, 88, 78, 74, 83 } ) );
    monkeys.push_back( new Monkey( []( unsigned long long worryLevel ){ return worryLevel + 5; }, 17, 3, 5, { 81, 58 } ) );
    #endif //TEST

    for( unsigned int round=0; round<10000; round++ )
    {
        for( Monkey* monkey: monkeys )
            monkey->execute( monkeys );
    }
    std::vector<unsigned long long> results = {};
    for( Monkey* monkey: monkeys )
        results.push_back( monkey->getTotalInspections() );

    std::sort( results.begin(), results.end() );
    std::cout << results[ results.size()-2 ] * results[ results.size()-1 ] << '\n';
}