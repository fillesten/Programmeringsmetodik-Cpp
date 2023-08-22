//
// Created by margi on 2022-11-22.
//

#include "Circle.h"
#include <cmath>
#include <iostream>


Circle::Circle(const std::string colour, double radius)
    :shape(colour),radius(radius) {
}

double Circle::getArea() const {
    //std::cout<<"Circle getArea"<<'\n';
    return (radius*radius) * M_PI;
}




