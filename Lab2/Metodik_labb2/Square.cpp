//
// Created by margi on 2022-11-25.
//

#include <iostream>
#include "Square.h"


Square::Square(const std::string colour, double radius)
: shape(colour), radius(radius) {
}

double Square::getArea() const {
    //std::cout<<"Square getArea"<<'\n';
    return radius*radius*4;
}
