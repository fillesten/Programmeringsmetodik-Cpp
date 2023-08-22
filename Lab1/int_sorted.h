//
// Created by margi on 2022-11-11.
//

#include <iostream>
#include <cstdlib>
#include <cstddef>
#include "int_buffer.h"
#ifndef METODIK_LAB1_INT_SORTED_H
#define METODIK_LAB1_INT_SORTED_H


class int_sorted {
public :
    int_sorted (const int* source, size_t size);
    int_sorted() = default;
    size_t size () const;
    void insert (int value);
    const int * begin () const;
    const int * end () const;
    int_sorted merge (const int_sorted &merge_with) const;

private:
    int_buffer intb = int_buffer(0);
};



#endif //METODIK_LAB1_INT_SORTED_H
