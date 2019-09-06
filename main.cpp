#include <iostream>
#define BOOST_NO_CXX11_SCOPED_ENUMS
//#include <boost/filesystem.hpp>
#undef BOOST_NO_CXX11_SCOPED_ENUMS
#include <math.h>
#include <vector>
#include "Fractal.h"
//#include "C:\Users\Owner\CLionProjects\cppEx1V2\boost_1_55_0\boost\filesystem.hpp"

void frctalDrawer1(int maxlvl, int lvl, bool first = false);
void frctalDrawer2(int maxlvl, int lvl, std::vector<std::string>& arr, bool first = false);

bool inCarpet(long x, long y) {
    while (x!=0 &&  y!=0)
    {
        if ((x % 2 == 1) && (y % 2 == 1))
        {
            return false;
        }
        x /= 2;
        y /= 2;
    }
    return true;
}

void carpet(int n)
{
    double power = pow(2,n);
    for(long i = 0; i < power; i++) {
        for(long j = 0; j < power; j++) {
            if(inCarpet(i,j))
            {
                std::cout << "#";
            }
            else
            {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }
}



int main() {
    std::cout << "Hello, World!" << std::endl;
    std::vector<std::string> arr;

    /*
    frctalDrawer2(2,2,arr);
    for (auto i = arr.begin(); i != arr.end(); ++i)
    {
        std::cout << *i;
    }
*/
    //carpet(3);
    //frctalDrawer1(2,2);

    Fractal *f1 = new FractalType1(1);
    Fractal *f2 = new FractalType2(2);
    Fractal *f3 = new FractalType3(3);

    f1->draw();
    std::cout << "\n -----------------------------------------\n";
    f2->draw();
    std::cout << "\n -----------------------------------------\n";
    f3->draw();
    return 0;
}

void frctalDrawer1(int maxlvl, int lvl, bool first)
{
    if(lvl > 0)
    {
        std::cout << std::endl;
        frctalDrawer1(maxlvl,lvl-1);
        frctalDrawer1(maxlvl,lvl-1);
        frctalDrawer1(maxlvl,lvl-1);
        std::cout << "\n";
        frctalDrawer1(maxlvl,lvl-1);
        for(int i = 0; i < pow(3,(lvl-1)); i++)
        {
            std::cout << " ";
        }
        frctalDrawer1(maxlvl,lvl-1);
        std::cout << std::endl;
        frctalDrawer1(maxlvl,lvl-1);
        frctalDrawer1(maxlvl,lvl-1);
        frctalDrawer1(maxlvl,lvl-1, true);
        //std::cout <<"#1";
        //std::cout << std::endl;

    }

    if(!first)
    {
        std::cout << "#";
    }


}

void frctalDrawer2(int maxlvl, int lvl, std::vector<std::string>& arr, bool first)
{
    if(lvl > 0)
    {
        std::cout << std::endl;
        frctalDrawer2(maxlvl,lvl-1, arr);
        frctalDrawer2(maxlvl,lvl-1, arr);
        frctalDrawer2(maxlvl,lvl-1, arr);
        arr.push_back("\n");
        frctalDrawer2(maxlvl,lvl-1, arr);
        for(int i = 0; i < pow(3,(lvl-1)); i++)
        {
            arr.emplace_back(" ");
            //std::cout << " ";
        }
        frctalDrawer2(maxlvl,lvl-1, arr);
        arr.emplace_back("\n");
        frctalDrawer2(maxlvl,lvl-1, arr);
        frctalDrawer2(maxlvl,lvl-1, arr);
        frctalDrawer2(maxlvl,lvl-1, arr, true);
        //std::cout << std::endl;

    }

    if(!first)
    {
        arr.emplace_back("#");
    }

}
