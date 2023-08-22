//
// Created by margi on 2022-11-23.
//

#ifndef METODIK_LABB2_PARALLELEPIPED_H
#define METODIK_LABB2_PARALLELEPIPED_H

#include "Rectangle.h"

class Parallelepiped:  public Rectangle{
private:
    double depth;
public:
    Parallelepiped(const std::string colour, double base, double height, double depth);
    double getArea() const;
};


#endif //METODIK_LABB2_PARALLELEPIPED_H
