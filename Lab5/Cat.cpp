//
// Created by margi on 2022-12-08.
//


#include "Cat.h"


Cat::Cat(const std::string &name, double lives)
: name(name), lives(lives) {}

bool Cat::operator==(const Cat &rhs) const {
    return name == rhs.name;
}

std::ostream &operator<<(std::ostream &os, const Cat &cat) {
    os << "name: " << cat.name << " lives: " << cat.lives;
    return os;
}

void MyPrint::operator()(const Cat &C ) {
        std::cout<< C.name <<" has " << C.lives<< " left."<<std::endl;
 }

CompLives::CompLives(int i) : i(i) { }

bool CompLives::operator()( const Cat &rhs) {
    return i < rhs.lives;
}

double SumLives::operator()(double add, const Cat& C) {
    return C.lives + add;
}

double MyUnOp::operator()(const Cat &C) {
    return C.lives;
}

MyFunc::MyFunc(double mean) : mean(mean) { }

double MyFunc::operator()(const Cat &C) {
    return C.lives - mean;
}


