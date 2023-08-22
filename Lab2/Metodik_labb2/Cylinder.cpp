//
// Created by margi on 2022-11-22.
//

#include <iostream>
#include "Cylinder.h"


Cylinder::Cylinder(const std::string colour, double radius, double height)
: shape(colour), Circle(colour, radius), height(height) {
}

double Cylinder::getArea() const {
    //std::cout<<"Cylinder getArea"<<std::endl;
    return Circle::getArea() * 2 + (2*M_PI*radius*height);
}








