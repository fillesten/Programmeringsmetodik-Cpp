#include <vector>
#include <array>
#include <algorithm>
#include <numeric>
#include "Cat.h"


/*
 1  klar
 2  hitta första objektet i vectorn vars double value är större än det angivna
    värdet
    //MyPrint() (*std::find_if(CatVec.begin(), CatVec.end(), cl));

 3
 4
 5
 6
 7
 8
 std::transform(CatVec.begin(), CatVec.end(), V2.begin(), [accumulate](Cat c) {
        return c.getLives() - accumulate;
});
    for (const auto &item: V2) { std::cout <<item<<", "; }
    std::cout<<std::endl;
 9
 */


int main() {

    Cat CatArr[7];

    Cat C1("Nova", 0);
    Cat C2("Pluto", 7);
    Cat C3("Pluto", 7);
    Cat C4("Nisse", 5);
    Cat C5("Meowe", 16);
    Cat C6("Howard", 20);
    Cat C7("Platos", 3);

    CatArr[0] = C1;
    CatArr[1] = C2;
    CatArr[2] = C3;
    CatArr[3] = C4;
    CatArr[4] = C5;
    CatArr[5] = C6;
    CatArr[6] = C7;
    std::vector<Cat> CatVec(std::begin(CatArr), std::end(CatArr));

    std::for_each(CatVec.begin(), CatVec.end(), MyPrint());             // 1
    std::cout<<std::endl;

    CompLives cl =  CompLives(10);                                      // 2
    auto foundCat =  std::find_if(CatVec.begin(), CatVec.end(), cl);
    if (foundCat != CatVec.end()) { MyPrint()(*foundCat); }
    std::cout<<std::endl;

    auto adjCat =  std::adjacent_find( CatVec.begin(), CatVec.end());   // 3
    if (adjCat != CatVec.end()) { MyPrint()(*adjCat); }
    std::cout<<std::endl;

    bool b = std::equal( std::begin(CatArr), std::end(CatArr), CatVec.begin(), CatVec.end());
    if(b) { std::cout<<"They are equal"<<std::endl; }                   // 4
    else std::cout<<"they are not equal"<<std::endl;
    Cat C8("Goofy", 20);
    CatVec.push_back(C8);
    b = std::equal( std::begin(CatArr), std::end(CatArr), CatVec.begin(), CatVec.end());
    if(b) { std::cout<<"They are equal"<<std::endl; }
    else  { std::cout<<"they are not equal"<<std::endl; }
    //CatVec.pop_back();

    auto ssCat = std::search(CatVec.begin(), CatVec.end(), CatArr +2, CatArr + 4);
    MyPrint()(*(ssCat));                                                // 5

    SumLives SL;
    double accumulate = std::accumulate(CatVec.begin(), CatVec.end(), 0.0, SL);
    accumulate = accumulate / CatVec.size();
    std::cout << accumulate<<" the mean /6"<<std::endl<<std::endl;                      // 6 sista 20 kmr från en push back


    std::vector<double> V2(CatVec.size());                              // 7
    MyUnOp mup;
    std::transform(CatVec.begin(), CatVec.end(), V2.begin(), mup);
    for (const auto &item: V2) { std::cout <<item<<", "; }
    std::cout<<"/7"<<std::endl;

    MyFunc mf(accumulate);                                              // 8
    std::transform(CatVec.begin(), CatVec.end(), V2.begin(), mf);
    for (const auto &item: V2) { std::cout <<item<<", "; }
    std::cout<<"/8"<<std::endl;

    std::sort(V2.begin(), V2.end());                                    // 9
    for (const auto &item: V2) { std::cout <<item<<", "; }
    std::cout<<std::endl;

}
