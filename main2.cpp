//
// Created by Owner on 06/09/2019.
//

#include <fstream>
#include <iostream>
#include <ostream>
#include "Fractal.h"
#include <vector>




bool isDigit(const char &ch)
{
    return(std::isdigit(ch));
}

bool isLegalFormat(std::string line, const char& typeOfFractal, const char& dimOfFractal)
{
    if(!isDigit(typeOfFractal) || line[1] != ',' || !isDigit(dimOfFractal))
    {
        return false;
    }
    return true;
}


int main()
{

    std::string line;
    std::ifstream out("/cs/usr/ori.frenkel/CLionProjects/cppEx2S/test.txt");
    std::vector<Fractal*> vec;

    while(getline(out, line))
    {
        if(line.length() != 3)
        {
            std::cerr << "Invalid input " << std::endl;
            exit(EXIT_FAILURE);
        }

        char typeOfFractal = line[0];
        char dimOfFractal = line[2];
        if(!isLegalFormat(line, typeOfFractal, dimOfFractal))
        {
            std::cerr << "Invalid input " << std::endl;
            exit(EXIT_FAILURE);
        }

        vec.push_back(FactoryFractal::createFractal((int) (typeOfFractal - '0'), (int) (dimOfFractal - '0')));

    }

    // print the vector content with reverse order
    for (auto iteratorFractal = vec.rbegin(); iteratorFractal != vec.rend(); ++iteratorFractal)
    {
        (*iteratorFractal)->draw();
        std::cout << std::endl;
    }



    out.close();
    return 0;
}
