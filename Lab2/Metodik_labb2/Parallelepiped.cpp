//
// Created by margi on 2022-11-23.
//

#include <iostream>
#include "Parallelepiped.h"

Parallelepiped::Parallelepiped(const std::string colour, double base, double height, double depth)
:shape(colour), Rectangle(colour, base, height), depth(depth) {

}

double Parallelepiped::getArea() const {

    //std::cout<<"Parallelepiped getArea"<<'\n';
    Rectangle side_Rec(Parallelepiped::getColour(), depth, height);
    Rectangle TB_Rec(Parallelepiped::getColour(), depth, base);
    return 2 * (Rectangle::getArea() + side_Rec.getArea() + TB_Rec.getArea()) ;
    //Rectangle::getArea()*2 + 2*r1.getArea() + 2*r2.getArea();
}

