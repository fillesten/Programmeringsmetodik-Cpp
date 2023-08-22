//
// Created by margi on 2022-11-03.
//
#include <iostream>
#include <cstdlib>
#ifndef METODIK_LAB1_INT_BUFFER_H
#define METODIK_LAB1_INT_BUFFER_H


class int_buffer {
public :
    explicit int_buffer (size_t size);
    int_buffer (const int* source, size_t size);
    int_buffer (const int_buffer& rhs); // copy construct

    int_buffer (int_buffer&& rhs) noexcept; // move construct, ger en r-value referens

    int_buffer& operator = (const int_buffer& rhs); // copy assign

    int_buffer& operator = (int_buffer&& rhs) noexcept; // move assign, ger en r-value referens


    int& operator [] (size_t index);
    const int& operator [] (size_t index) const;

    int* begin();
    int* end();
    const int* begin() const;
    const int* end() const;

    size_t size() const;



    ~int_buffer(); // destruktor
private:
    void swap(int_buffer& rhs);
    int* start;
    size_t length;
};

#endif //METODIK_LAB1_INT_BUFFER_H
