//
// Created by margi on 2022-11-22.
//qwer

#ifndef METODIK_LABB2_SHAPE_H
#define METODIK_LABB2_SHAPE_H
#include <string>

class shape {
private:
    std::string colour;
public:

    shape(const std::string &colour);

     virtual double getArea() const = 0;
     virtual ~shape() = default;
     const std::string &getColour() const;
};


#endif //METODIK_LABB2_SHAPE_H
