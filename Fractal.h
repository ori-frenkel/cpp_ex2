//
// Created by Owner on 04/09/2019.
//

#ifndef CPPEX2_FRACTAL_H
#define CPPEX2_FRACTAL_H
#include <math.h>


class Fractal
{
protected:
    int _dim = 0; /**< the dimension of the matrix */
    long _numberOfLines; /**< number of row/column (row = column) in the matrix
                            *(representing the Fractal as 2d array/matrix */
public:
    /**
     * Constructor
     * @param dim he dimension of the matrix
     */
    Fractal(int dim):_dim(dim){};

    /**
     * each of the derived function need to implement draw function.
     * This function prints the Fractal
     */
    virtual void draw() = 0;
};

class FractalType1 : public Fractal
{
private:
    /**
     * (0,0) |(0,1) | (0,2)      #  , #  ,   #
     * (1,0) | (1,1)| (1,2)      #  , space, #
     * (2,0) | (2,1)| (2,2)      #  ,  # ,   #
     * as it can be seen there is space in x%3 ==1 and y%3 == 1
     * meaning if x == 1 and  y == 1 than there is space
     * @param x - coordinate of x in matrix
     * @param y - coordinate of x in matrix
     * @return - true if in (x,y) should be '#" false otherwise.
     */
    bool inMatrix(long x, long y) const;

public:
    FractalType1(int dim) : Fractal(dim) { _numberOfLines = static_cast<long>(pow(3, _dim));}
    void draw() override;

};

class FractalType2 : public Fractal
{
private:
    bool inMatrix(long x, long y) const;

public:
    FractalType2(int dim) : Fractal(dim) { _numberOfLines = static_cast<long>(pow(2, _dim));}
    void draw() override;
};

class FractalType3 : public Fractal
{
private:
    bool inMatrix(long x, long y) const;

public:
    FractalType3(int dim) : Fractal(dim) {_numberOfLines = static_cast<long>(pow(3, _dim));}
    void draw() override;

};

class FactoryFractal
{
public:
    static Fractal* createFractal(int typeOfFractal, int dim);

};

#endif //CPPEX2_FRACTAL_H
