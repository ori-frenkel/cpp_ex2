//
// Created by Owner on 06/09/2019.
//

#include <fstream>
#include <iostream>
#include "main2.h"
#include <ostream>
using namespace std;
int main()
{
    //std::ifstream input( "C:\\Users\\Owner\\CLionProjects\\cppEx2\\test.txt" );


    string line;
    ifstream out("C:\\Users\\Owner\\CLionProjects\\cppEx2\\test.txt");
    while(getline(out, line)) {
        //cout << line << endl;
        cout << line[3] << endl;
        if(line[3] == '\n')
        {
            exit(100);
        }

    }
    out.close();
    return 0;
}
