// Created by fist2000 on 2022-11-03.
#include "int_buffer.h"
#include <algorithm>

int_buffer::int_buffer(size_t size)
    :start (new int [size]), length(size){
        //std::cout<<"buffer explicit constructor\n";
}

//rezise function typ
int_buffer::int_buffer ( const int* source , size_t size)
    : int_buffer(std::distance(source, source+size)){
        std::copy(source, source+size, this->start);
    //std::cout<<"buffer constructor with *source_ptr and size_t\n";
}

/*
int_buffer a(10); -> int_buffer b(a);
were this = b | rhs = a                             */
// copy construct b created from already existing a
int_buffer::int_buffer(const int_buffer& rhs)
    :int_buffer(rhs.start, rhs.size()){

    //copies rhs into the this->start that comes from the begin() funk
    //std::cout<<"buffer copy constructor \n";
}

/*
int a = 20;
a sparas eftersom den deklareras medans 20 är endast
ett int som temporärt används och som sen försvinner när raden är färdig
en r-value referens gör så man sparar en referens till 20
som sen kan användas igen så typ
int&& r_f = 30;
a = r_f; gör a till 30
*/
//move construct
int_buffer::int_buffer (int_buffer&& rhs) noexcept
    :start(nullptr), length(0) {
        swap(rhs);
    //std::cout<<"buffer move constructor \n";
}

// copy assign
int_buffer& int_buffer::operator =(const int_buffer& rhs ) {
    int_buffer temp(rhs);
    swap(temp);
    //std::cout<<"buffer copy assign \n";
    return *this;

}

//move assign
int_buffer& int_buffer::operator =(int_buffer&& rhs ) noexcept {
    swap(rhs);
    //std::cout<<"buffer move assign \n";
    return *this;

}

/*
 returners an int_reference inside of the array/buffer
 specified by index */
// index reference
int& int_buffer::operator [](size_t index){
    //std::cout<<"buffer reference of index \n";
    return *(begin() + index);
}

// const index reference
const int& int_buffer::operator [](size_t index) const{
    //std::cout<<"buffer const reference of index \n";
    return *(begin() + index);
}

// THIS IS THe correct one, according to angas
//returns pointer to the start of the buffer
int* int_buffer::begin (){
    //std::cout<<"pointer to start of buffer \n";

    return start;
}

//returns pointer to the end of the buffer
int* int_buffer::end (){
    //std::cout<<"pointer to end of buffer \n";
    return start + length;
}

//returns const pointer to the start of the buffer
const int* int_buffer::begin () const {
    //std::cout<<"const pointer to start of buffer \n";
    return start;
}

//returns const pointer to the end of the buffer
const int* int_buffer::end () const {
    //std::cout<<"const pointer to end of buffer \n";
    return start + length;
}

//returns size of the buffer
size_t int_buffer::size () const{
    //std::cout<<"buffer size" << length << "\n";
    return length;
}

void int_buffer::swap(int_buffer& rhs){
    //std::cout << "buf passed to swap"<< std::endl;
    std::swap(this->start, rhs.start);
    std::swap(this->length, rhs.length);
}

int_buffer::~ int_buffer () {
    //std::cout<<"buffer destructor \n";
    delete [] start;
}














