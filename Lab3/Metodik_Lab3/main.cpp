#include <iostream>
#include "p_queue.h"

#include<cstdlib>
#include<ctime>



//bool price_by_size(const price& lhs, const price& rhs) { return lhs.a < rhs.a; }

struct order {
    std::string name;
    int value;
};


struct CompareOrderValue{
    bool operator()(const order& lhs, const order& rhs) {
        return lhs.value < rhs.value;
    }
};

void createOrders(const std::string& name, p_queue<order, CompareOrderValue>&queue){
    for (int i = 0; i < 7; ++i) {
        order o = { name, (rand() % (31-15) +15)};
        queue.push(o);

    }
}




int main() {

    srand(time(0));

    p_queue <order, CompareOrderValue> buyQ;
    p_queue <order, CompareOrderValue> sellQ;

    std::vector<std::string> investors = {"Joakim von Anka", "Bruce Wayne", "Patrick Bateman" };

    for (const auto &investor: investors) {
        createOrders(investor, buyQ);
        createOrders(investor, sellQ);
    }


    int i = 0;
    order orderB = buyQ.pop();
    order orderS = sellQ.pop();

    while (!buyQ.empty() ) {
         if (orderB.value >= orderS.value) {
            std::cout<<orderB.name<< " buys with "<< orderB.value<<
            " Swedish dollares from ->" <<orderS.name<<"s stock at the price "<<orderS.value<<std::endl;
            orderS = sellQ.pop();
            orderB = buyQ.pop();
            i++;
        }
        else {
            orderB = buyQ.pop();
        }

    }
    std::cout<<"There was a total of "<<i << " purchases this day :)"<<std::endl;
    return 0;
}
