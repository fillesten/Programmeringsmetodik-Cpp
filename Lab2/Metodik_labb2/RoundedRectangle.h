//
// Created by margi on 2022-11-23.
//

#ifndef METODIK_LABB2_ROUNDEDRECTANGLE_H
#define METODIK_LABB2_ROUNDEDRECTANGLE_H

#include "Rectangle.h"
#include "Circle.h"

class RoundedRectangle:  public Rectangle {
private:

    double radius;
public:
    RoundedRectangle(std::string colour, double base, double height, double radius);
    double getArea() const;

};


#endif //METODIK_LABB2_ROUNDEDRECTANGLE_H
