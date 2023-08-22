//
// Created by margi on 2022-11-23.
//

#include <iostream>
#include "RoundedRectangle.h"
#include "Square.h"
#include "cmath"


RoundedRectangle::RoundedRectangle(std::string colour, double base, double height, double radius)
    : shape(colour), Rectangle(colour, base, height), radius(radius) { }


double RoundedRectangle::getArea() const {
    //std::cout<<"RoundedRectangle getArea"<<'\n';
    Circle cornerCircle(Rectangle::getColour(),radius);
    Square cornerSquare(Rectangle::getColour(), radius);
    return Rectangle::getArea() - cornerSquare.getArea() + cornerCircle.getArea();
    //     Rectangle            - small Square            + Circle
    // total area of corner square is area of a square of base & height = radius * 4
    /*
    return Rectangle::getArea() - (4*radius*radius) + (radius*radius*M_PI);
    return Rectangle::getArea() - (4*radius*radius) + Circle::getArea(); //multiple inheritance
    */
}