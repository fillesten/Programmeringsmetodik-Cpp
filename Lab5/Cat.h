//
// Created by margi on 2022-12-08.
//

#ifndef METODIK_LAB5_CAT_H
#define METODIK_LAB5_CAT_H
#include <iostream>
#include <vector>

class Cat {

private:
    std::string name;
    double lives;

    friend struct MyPrint;
    friend struct CompLives;
    friend struct SumLives;
    friend struct MyUnOp;
    friend struct MyFunc;

public:

    Cat() = default;
    Cat(const std::string &name, double lives);

    bool operator==(const Cat &rhs) const;

    friend std::ostream &operator<<(std::ostream &os, const Cat &cat);
};

struct MyPrint{ void operator()(const Cat &C ); };

struct CompLives {
    int i;
    explicit CompLives(int i);
    bool operator ()(const Cat &C );
};

struct SumLives {
    double operator()(double add, const Cat& C);
};

struct MyUnOp {
    double operator()(const Cat& C);
};

struct MyFunc {
    double mean;
    explicit MyFunc(double mean);
    double operator ()(const Cat& C);
};

#endif //METODIK_LAB5_CAT_H

