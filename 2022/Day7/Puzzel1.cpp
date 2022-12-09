#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include "StringUtils.hpp"

int totalamount = 0;

class filesystemobject
{
public:
    filesystemobject(std::string name, filesystemobject* parent) :
        name(name),
        parent(parent)
    {}

    virtual int getSize() = 0;

    std::string name;
    filesystemobject* parent;
};

class filesystemfolder : public filesystemobject
{
public:
    filesystemfolder(std::string name, filesystemobject* parent) :
        filesystemobject(name, parent)
    {}
    void addChild(filesystemobject* child)
    {
        children.push_back(child);
    }

    int getSize() override
    {
        int total = 0;
        for (auto* child : children)
            total += child->getSize();

        if (total <= 100000)
            totalamount+=total;
        return total;
    }

private:
    std::vector<filesystemobject*> children = {};
};

class filesystemfile : public filesystemobject
{
public:
    filesystemfile(std::string name, filesystemobject* parent, int size) :
        filesystemobject(name, parent),
        size(size)
    {}

    int getSize() override
    {
        return size;
    }

private:
    int size;
};

int main()
{
    std::ifstream inputFile("input.txt");
    std::vector<std::string> input = {};
    std::string temp;

    while (std::getline(inputFile, temp))
        input.push_back(temp);

    filesystemfolder* currentDir = NULL;

    for (auto line : input)
    {
        std::vector<std::string> inputData = StringUtils::splitString(line, ' ');
        if (inputData[0] == "$")
        {
            if (inputData[1] == "cd")
            {
                if (inputData[2] == "..")
                    currentDir = (filesystemfolder*)currentDir->parent;
                else
                {
                    filesystemfolder* tempdir = new filesystemfolder(inputData[2], currentDir);
                    if (currentDir)
                        currentDir->addChild(tempdir);
                    currentDir = tempdir;
                }
            }
        }
        else if (inputData[0] != "dir")
        {
            currentDir->addChild(new filesystemfile(inputData[1], currentDir, std::stoi(inputData[0])));
        }
    }
    while (currentDir->parent != NULL)
    {
        currentDir = (filesystemfolder*)currentDir->parent;
    }
    filesystemfolder* root = currentDir;
    
    std::cout << totalamount << '\n';
}