#include "int_buffer.h"
#include "int_sorted.h"

void f(int_buffer buf) {
    std::cout << "buf passed to function f"<< std::endl;

    int num = 1;
    //assign buf values  1 to 10
    for (int *i = buf.begin(); i != buf.end(); i++) {
        *i = num++;
    }

    //prints out contents in buf
    /*for(const int* i = buf.begin(); i != buf.end(); i++ ) {
        std::cout<<"index "<< i <<" contains " << *i <<std::endl;
    }*/
    /*for (auto e: buf) {

        e = num++;
    }*/
    for (auto e : buf) {
        std::cout<<"contains " << e <<std::endl;

    }
}


/*int_sorted sort(const int *begin, const int *end) {

    if (begin == end) { //pekar begin och end på samma adress
        return int_sorted(nullptr, 0);
    }

    if (begin == end - 1) { return int_sorted(begin, 1);}


    ptrdiff_t half = (end - begin) / 2;
    const int* mid = begin + half;
    return sort (begin, mid).merge( sort(mid,end));
}*/



int main() {

    srand (time(NULL));

    int_buffer buf(15);
    /*int_buffer buff2(buf);*/
    //f(buf);

    for (int *i = buf.begin(); i != buf.end(); i++) {
        *i = rand() % 100 + 1;
    }

    for(auto element: buf){
        std::cout << element << " ";
    }
    std::cout<<std::endl;

    int_sorted is(buf.begin(), buf.size());

    //.sort(buf.begin(), buf.size());

    //int_sorted is = sort(buf.begin(), buf.size());
    //int_sorted temp = is.sort(is.begin(),is.end());

    std::cout<<std::endl;
    int j = 0;
    for(const int* i = is.begin(); i != is.end(); i++ ) {

        std::cout<<"index "<< i<<" alternatively "<< j++ <<" contains " << *i <<std::endl;
    }
    /*int_sorted is;
    for (int i = 0; i < 200; ++i) {
        is.insert(rand() % 100 + 1);
    }*/

    /*
    int j = 0;
    for(const int* i = is.begin(); i != is.end(); i++ ) {

        std::cout<<"index "<< i<<" alternativt "<< j++ <<" contains " << *i <<std::endl;
    }*/
    /*for (auto e : is) {

        std::cout<<"index "<< &e <<" contains " << e <<std::endl;

    }*/










        return 0;
}
