//
// Created by Owner on 04/09/2019.
//

#ifndef CPPEX2_FRACTAL_H
#define CPPEX2_FRACTAL_H
#include <math.h>
#include <iostream>



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

    /**
     * Destructor
     */
    virtual ~Fractal() = default;
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

    /**
     * Constructor
     * @param dim - dimension of the fractal
     */
    FractalType1(int dim) : Fractal(dim) { _numberOfLines = static_cast<long>(pow(3, _dim));}

    /**
     * Drawing the fractal
     */
    void draw() override;

    /**
     * Copy constructor - explicit, allowing to copy only the same type
     * There is no logic type 1 = type 2 (because those are different fractals)
     * @param other
     */
    explicit FractalType1(const FractalType1& other) = default;

    /**
     * Move Constructor
     * @param other - object to copy using move
     */
    FractalType1(FractalType1&& other) noexcept = default;

    /**
     * Copy - Assignment Operator
     * @param other - object to assign to current object
     * @return - reference to the current object after assign to it the other object
     */
    FractalType1& operator = (const FractalType1& other);


    /**
     * Move assignment
     * @param other - object to assign to current using move
     */
    FractalType1& operator = (FractalType1&& other) noexcept = default;


    /**
     * destructor
     */
    ~FractalType1() override  = default;

};

class FractalType2 : public Fractal
{
private:
    /**
     * (0,0) |(0,1)     #  ,   #
     * (1,0) | (1,1)    #  , space
     * as it can be seen there is space in x%2 ==1 and y%2 == 1
     * meaning if x%2 == 1 and  y%2 == 1 than there is space
     * @param x - coordinate of x in matrix
     * @param y - coordinate of x in matrix
     * @return - true if in (x,y) should be '#" false otherwise.
     */
    bool inMatrix(long x, long y) const;

public:
    /**
     * Constructor
     * @param dim - dimension of the fractal
     */
    FractalType2(int dim) : Fractal(dim) { _numberOfLines = static_cast<long>(pow(2, _dim));}

    /**
     * Drawing the fractal
     */
    void draw() override;

    /**
     * Copy constructor - explicit, allowing to copy only the same type
     * There is no logic type 1 = type 2 (because those are different fractals)
     * @param other
     */
    explicit FractalType2(const FractalType2& other) = default;

    /**
     * Move Constructor
     * @param other - object to copy using move
     */
    FractalType2(FractalType2&& other) noexcept = default;

    /**
     * Copy - Assignment Operator
     * @param other - object to assign to current object
     * @return - reference to the current object after assign to it the other object
     */
    FractalType2& operator = (const FractalType2& other);


    /**
     * Move assignment
     * @param other - object to assign to current using move
     */
    FractalType2& operator = (FractalType2&& other) noexcept = default;


    /**
     * destructor
     */
    ~FractalType2() override  = default;
};

class FractalType3 : public Fractal
{
private:
    /**
     * (0,0) |(0,1) | (0,2)          #  , space ,    #
     * (1,0) | (1,1)| (1,2)      space  , space , space
     * (2,0) | (2,1)| (2,2)          #  , space ,    #
     * as it can be seen there is space in x%3 ==1 or y%3 == 1
     * meaning if x % 3 == 1 or  y % 3 == 1 than there is space
     * @param x - coordinate of x in matrix
     * @param y - coordinate of x in matrix
     * @return - true if in (x,y) should be '#" false otherwise.
     */
    bool inMatrix(long x, long y) const;

public:

    /**
     * Constructor
     * @param dim - dimension of the fractal
     */
    FractalType3(int dim) : Fractal(dim) {_numberOfLines = static_cast<long>(pow(3, _dim));}

    /**
     * Drawing the fractal
     */
    void draw() override;

    /**
 * Copy constructor - explicit, allowing to copy only the same type
 * There is no logic type 1 = type 2 (because those are different fractals)
 * @param other
 */
    explicit FractalType3(const FractalType3& other) = default;

    /**
     * Move Constructor
     * @param other - object to copy using move
     */
    FractalType3(FractalType3&& other) noexcept = default;

    /**
     * Copy - Assignment Operator
     * @param other - object to assign to current object
     * @return - reference to the current object after assign to it the other object
     */
    FractalType3& operator = (const FractalType3& other);


    /**
     * Move assignment
     * @param other - object to assign to current using move
     */
    FractalType3& operator = (FractalType3&& other) noexcept = default;


    /**
     * destructor
     */
    ~FractalType3() override  = default;

};

class FactoryFractal
{
public:
    /**
     * implementing factory design pattern
     * @param typeOfFractal - type of fractal (1,2,3)
     * @param dim - dimension of the fractal
     * @return - fractal from the given type and dimension
     */
    static Fractal* createFractal(int typeOfFractal, int dim);

};

#endif //CPPEX2_FRACTAL_H
