//
// Created by Owner on 05/09/2019.
//
#include <iostream>
//#include <boost/filesystem.hpp>
//#include "../cppEx1V2/boost_1_55_0/boost/filesystem.hpp"
//#include "../cppEx1V2/boost_1_55_0/boost/filesystem/path.hpp"


//using namespace boost::filesystem;
// TODO : remmber, when open file to close the file at the end/ before exiting with error
int main(int argc, char* argv[])
{
    // This program should only get path to one file.
    if(argc != 2)
    {
        std::cerr << "Usage: FractalDrawer <file path>" << std::endl;
        exit(EXIT_FAILURE);
    }

    /*
    path path(argv[1]);
    // checking if the path actually exist
    if (!boost::filesystem::exists(argv[1]))
    {
        std::cerr << "Invalid input " << std::endl;
        exit(EXIT_FAILURE);
    }
    if (!is_regular_file(path) || is_directory(path))
    {
        std::cerr << "Invalid input " << std::endl;
        exit(EXIT_FAILURE);
    }

    */


    return 0;
}