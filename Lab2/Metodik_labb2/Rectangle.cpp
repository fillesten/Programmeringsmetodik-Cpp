//
// Created by margi on 2022-11-22.
//

#include <iostream>
#include "Rectangle.h"

Rectangle::Rectangle(std::string colour, double base, double height)
: shape(colour), base(base), height(height){

}

double Rectangle::getArea() const {
    //std::cout<<"Rectangle getArea"<<'\n';
    return base*height;

}



