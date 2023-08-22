//
// Created by margi on 2022-11-25.
//

#ifndef METODIK_LABB2_SQUARE_H
#define METODIK_LABB2_SQUARE_H

#include "shape.h"

class Square : virtual public shape{
private:
    double radius;
public:
    Square(const std::string colour, double radius);
    double getArea()const;
};


#endif //METODIK_LABB2_SQUARE_H
