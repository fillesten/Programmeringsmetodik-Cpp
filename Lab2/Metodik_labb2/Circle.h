//
// Created by margi on 2022-11-22.
//

#ifndef METODIK_LABB2_CIRCLE_H
#define METODIK_LABB2_CIRCLE_H

#include "shape.h"

class Circle: virtual public shape {
protected:
    double radius;
public:
    Circle(const std::string colour, double radius);
    double getArea() const;
};


#endif //METODIK_LABB2_CIRCLE_H
