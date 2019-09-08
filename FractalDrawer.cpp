//
// Created by Ori Frenkel on 05/09/2019.
//
#include <iostream>
#include <boost/filesystem.hpp>
#include <fstream>
#include <iostream>
#include <ostream>
#include "Fractal.h"
#include <vector>

using namespace boost::filesystem;

/**
 *
 * @param ch - char
 * @return - true if its a digit (0-9)
 */
bool isDigit(const char &ch)
{
    return(std::isdigit(ch));
}

/**
 * Checking that the line format is legal
 * @param line - line from the input file
 * @param typeOfFractal - type of fractal line[0])
 * @param dimOfFractal - dim of fractal (line[2])
 * @return true if the line format legal, false otherwise.
 */
bool isLegalFormat(std::string line, const char& typeOfFractal, const char& dimOfFractal)
{
    if(!isDigit(typeOfFractal) || line[1] != ',' || !isDigit(dimOfFractal))
    {
        return false;
    }

    const int typeOfFractalInt = typeOfFractal - '0';
    const int dimfFractalInt = dimOfFractal - '0';
    // fractal type should be between 1 and 3 (include) and dim should be between 1 and 6 (include)
    if(typeOfFractalInt < 1 || typeOfFractalInt > 3 || dimfFractalInt < 1 || dimfFractalInt > 6)
    {
        return false;
    }
    return true;
}


/**
 * because this is vectors of pointers and not vector of object, the destructor won't be called
 * automatically
 * @param vec - vector that contains all the Fractals.
 */
void deleteVectorContents(std::vector<Fractal*> vec)
{
    for(Fractal *fractal : vec)
    {
        delete(fractal);
    }
    vec.clear();
}

/**
 * Main function - drawing fractals from file (given in command line)
 * @param argc
 * @param argv
 * @return 0 on success, any other number of failure.
 */
int main(int argc, char* argv[])
{
    // This program should only get path to one file.
    if(argc != 2)
    {
        std::cerr << "Usage: FractalDrawer <file path>" << std::endl;
        exit(EXIT_FAILURE);
    }


    path p(argv[1]);
    // checking if the path actually exist
    if (!exists(p))
    {
        std::cerr << "Invalid input" << std::endl;
        exit(EXIT_FAILURE);
    }
    if (!is_regular_file(p) || is_directory(p))
    {
        std::cerr << "Invalid input" << std::endl;
        exit(EXIT_FAILURE);
    }



    std::string line;
    std::ifstream input(argv[1]);
    std::vector<Fractal*> vecOfFractals;

    /* iterating line by line and creating vectors with all the Fractals (if one of the line is
       in wrong format exit with error) */
    while(getline(input, line))
    {
        // format should be exactly 3 chars (num,num)
        if(line.length() != 3)
        {
            input.close();
            deleteVectorContents(vecOfFractals);
            std::cerr << "Invalid input" << std::endl;
            exit(EXIT_FAILURE);
        }

        char typeOfFractal = line[0];
        char dimOfFractal = line[2];
        if(!isLegalFormat(line, typeOfFractal, dimOfFractal))
        {
            input.close();
            deleteVectorContents(vecOfFractals);
            std::cerr << "Invalid input" << std::endl;
            exit(EXIT_FAILURE);
        }

        try
        {
            vecOfFractals.push_back(FactoryFractal::createFractal((int) (typeOfFractal - '0'), \
                                                    (int) (dimOfFractal - '0')));
        }
        catch(const std::exception&)
        {
            input.close();
            deleteVectorContents(vecOfFractals);
            std::cerr << "Memory allocation failed" << std::endl;
            exit(EXIT_FAILURE);
        }

    }

    // print the vector content with reverse order
    for (auto iteratorFractal = vecOfFractals.rbegin(); iteratorFractal != vecOfFractals.rend(); \
                                                         ++iteratorFractal)
    {
        (*iteratorFractal)->draw();
        std::cout << std::endl;
    }
    deleteVectorContents(vecOfFractals);
    input.close();

    return 0;
}