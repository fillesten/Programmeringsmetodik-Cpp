//
// Created by margi on 2022-11-22.
//

#ifndef METODIK_LABB2_CYLINDER_H
#define METODIK_LABB2_CYLINDER_H

#include "Circle.h"
#include <cmath>

class Cylinder: public Circle {

    double height;
public:
    Cylinder(const std::string colour, double radius, double height);
    double getArea() const;
};


#endif //METODIK_LABB2_CYLINDER_H
