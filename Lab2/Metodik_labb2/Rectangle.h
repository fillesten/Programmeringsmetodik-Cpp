//
// Created by margi on 2022-11-22.
//

#ifndef METODIK_LABB2_RECTANGLE_H
#define METODIK_LABB2_RECTANGLE_H

#include "shape.h"


class Rectangle: virtual public shape {
protected:
    double base;
    double height;
public:
    Rectangle(std::string colour, double base, double height);
    double getArea() const;
};



#endif //METODIK_LABB2_RECTANGLE_H
