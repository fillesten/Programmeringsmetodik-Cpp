//
// Created by margi on 2022-11-11.
//

#include "int_sorted.h"
#include <algorithm>


int_sorted sort(const int *begin, const int *end) {

    std::cout<<"Sort function"<< std::endl;
    std::cout<<"contains ";
    for(const int* i = begin; i != end; i++ ) {

        std::cout<< *i <<" ";
    }
    std::cout<<std::endl;

    //if ptrs point to same locaiton = 0 elements
    if (begin == end) { return int_sorted(nullptr, 0); }

    //when its only 1 element
    if (begin == end - 1) { return int_sorted(begin, 1);}

    ptrdiff_t half = (end - begin) / 2;
    const int* mid = begin + half;
    return sort (begin, mid).merge( sort(mid,end));
}


int_sorted::int_sorted(const int *source, size_t size) {
    if (size > 1) {
        intb = sort(source, source+size).intb;
    }
    else {
        intb = int_buffer(source, size);
    }

    
    //denna ska sortera vid skapning
}



size_t int_sorted::size()const{


    //std::cout<<"buffer size from int sorted " << intb.size() << "\n";
    return intb.size();
}

void int_sorted::insert(int value){

   int_sorted temp = int_sorted(&value, 1);
   *this = merge(temp);
}

const int* int_sorted::begin() const{

    return intb.begin();
}

const int* int_sorted::end()const{

    return intb.end();
}

int_sorted int_sorted::merge(const int_sorted &merge_with ) const {

    std::cout<<"Merge function";
    int_buffer tempbuf(this->size() + merge_with.size());

    const int* ptr_a = this->begin();
    const int* ptr_b = merge_with.begin();
    int i=0;
    while (ptr_a != this->end() && ptr_b != merge_with.end()) {

        if (*ptr_a < *ptr_b) {
            tempbuf[i]= *ptr_a;
            ptr_a++;
        }
        else {
            tempbuf[i]= *ptr_b;
            ptr_b++;
        }
        i++;
    }
    while (ptr_a != this->end()) {
        tempbuf[i]= *ptr_a++;
        //ptr_a++;
        i++;
    }
    while (ptr_b != merge_with.end()) {
        tempbuf[i]= *ptr_b;
        ptr_b++;
        i++;
    }

    //endast utskrift
    std::cout<<" this contains ";
    for(const int* k = this->begin(); k != this->end(); k++ ) {
        std::cout<< *k <<" ";
    }
    std::cout<<"rhs contains ";
    for(const int* l = merge_with.begin(); l != merge_with.end(); l++ ) {
        std::cout<< *l <<" ";
    }
    std::cout<<std::endl;

    int_sorted is(nullptr, 0);//stoppa in tempbuf i is

    is.intb=tempbuf;

    return is;
    //int_sorted(tempbuf.begin(), tempbuf.size());
}




