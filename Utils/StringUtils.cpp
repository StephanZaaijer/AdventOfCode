#include "StringUtils.hpp"

std::vector<std::string> StringUtils::splitString( const std::string &input, const char &identifier)
{
    std::vector<std::string> output = {};
    std::string temp = "";

    for(auto character: input )
    {
        if( character == identifier )
        {
            output.push_back( temp );
            temp = "";
        }
        else
        {
            temp += character;
        }
    }
    if( temp != "" )
        output.push_back( temp );
    return output;
}