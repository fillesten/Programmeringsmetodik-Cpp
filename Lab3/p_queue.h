//
// Created by margi on 2022-11-30.
//
/*
 * https://stackoverflow.com/questions/495021/why-can-templates-only-be-implemented-in-the-header-file
 Mallfunktioner deklareras i samband med deras definition
 så deras deklaration och definition är samma sak.

 Så för klasser med template och typename skiljer man inte på
 definitionsfil och implementeringsfil
*/

#ifndef METODIK_LAB3_P_QUEUE_H
#define METODIK_LAB3_P_QUEUE_H
#include <vector>
#include <functional>
#include <string>

/*template<typename T, typename Comp = std::CompareOrderValue<T>> //från martin
T find_min(T first, T last, Comp comp = Comp()) {
    T min = first;
    while (first != last) {
        if (comp(*first, *min))
            min = first;
        first++;
    }
    return min;
}

template<typename T, typename Comp = std::CompareOrderValue<T>>
void selection_sort(T first, T last, Comp comp = Comp()) {
    while (first != last) {
        auto min = find_min(first, last, comp);
        using std::iter_swap;
        iter_swap(first, min);
        first++;
    }
}*/





template<typename T, typename Comp = std::less<>>
class p_queue {
private:
    std::vector<T> vec;
    Comp cmp;
public:

    T pop() { //pop körs när man köper / matching har hittats
        T first = vec.front();
        vec.erase(vec.begin());
        return first;
    }
    void push(T e) {
        std::vector<T> target;
        std::merge(vec.begin(),vec.end(), &e, &e + 1, std::back_inserter(target), cmp);
        vec = std::move(target);
    }
    int size() {
        return vec.size();
    }
    bool empty() {
        if (vec.empty()) { return true; }
        else { return false; }
    }
};

#endif //METODIK_LAB3_P_QUEUE_H
