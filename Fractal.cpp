//
// Created by Owner on 04/09/2019.
//
#include "Fractal.h"

/**
 * Sierpinski Carpet Fractal Drawer (type 1)
 */
void FractalType1::draw()
{
    for(long i = 0; i < _numberOfLines; i++) {
        for(long j = 0; j < _numberOfLines; j++) {
            if(inMatrix(i,j))
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

/**
 * (0,0) |_(0,1)| (0,2)      #  , #  ,   #
 * (1,0) | (1,1)| (1,2)      #  , space, #
 * (2,0) | (2,1)| (2,2)      #  ,  # ,   #
 * as it can be seen there is space in x%3 ==1 and y%3 == 1
 * meaning if x == 1 and  y == 1 than there is space
 * @param x - coordinate of x in matrix
 * @param y - coordinate of x in matrix
 * @return - true if in (x,y) should be '#" false otherwise.
 */
bool FractalType1::inMatrix(long x, long y) const
{
    while (x != 0 &&  y !=0 )
    {
        if ((x % 3 == 1) && (y % 3 == 1))
        {
            return false;
        }
        x /= 3;
        y /= 3;
    }
    return true;
}

/**
 * (0,0) |_(0,1)| (0,2)      #  , space,   #
 * (1,0) | (1,1)| (1,2)    space, space, space
 * (2,0) | (2,1)| (2,2)      #  , space,   #
 * as it can be seen there is space in x%3 ==1 or y%3 == 1
 * meaning if x or y == 1 than there is space
 * @param x - coordinate of x in matrix
 * @param y - coordinate of x in matrix
 * @return - true if in (x,y) should be '#" false otherwise.
 */
bool FractalType3::inMatrix(long x, long y) const
{
    while (x!=0 || y!=0)
    {
        if ((x % 3 == 1) || (y % 3 == 1))
        {
            return false;
        }
        x /= 3;
        y /= 3;
    }
    return true;
}

/**
 * Draw Cantor Dust Fractals, check using inMatrix function if there is a need to print
 * '#' in (x,y)
 */
void FractalType3::draw()
{
    for(long i = 0; i < _numberOfLines; i++) {
        for(long j = 0; j < _numberOfLines; j++) {
            if(inMatrix(i,j))
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

bool FractalType2::inMatrix(long x, long y) const
{
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

void FractalType2::draw()
{
    for(long i = 0; i < _numberOfLines; i++) {
        for(long j = 0; j < _numberOfLines; j++) {
            if(inMatrix(i,j))
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

Fractal* FactoryFractal::createFractal(int typeOfFractal, int dim)
{
    switch(typeOfFractal)
    {
        case 1 : return new FractalType1(dim);
        case 2 : return new FractalType2(dim);
        case 3 : return new FractalType3(dim);
        default:return nullptr;
    }
}
