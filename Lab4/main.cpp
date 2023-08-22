#include <iostream>
#include "Email.h"
#include <tuple>
#include <vector>
#include "MailBox.h"

//tuple test - kan lösa del 1 av labben / är typ hela del 1 som vi ska lösa själv
/*
std::tuple<std::string,std::string,std::string> tplTest;
std::get<0>(tpl1) = "Anders";
std::get<1>(tpl1) = "2022-12-06";
std::get<2>(tpl1) = "lab 1";
auto tpl1 = std::make_tuple("Anders", "2022-12-06", "lab 1");
std::tuple tpl2 = std::make_tuple("Anders", "2022-12-06", "lab 2");
auto tpl3 = std::make_tuple("Anders", "2022-12-06", "lab 1");

if (email1.compareEmail(email2)) {
    std::cout<<"sant"<<std::endl;
}
else {
    std::cout<<"falskt"<<std::endl;
}*/


template<typename Cont>
void Show(const Cont& e) {
    for (const auto &item: e) {
        std::cout << item;
    }
}


int main() {

    Email email1("Anders", "10", "lab 3");
    Email email2("Martin", "20", "lab 2");
    Email email3("Anders", "30", "lab 1");
    Email email4("Filip", "10", "lab 2");
    Email email5("Filip", "30", "lab 2");

    MailBox mb;

    mb.mvPush(email2);
    mb.mvPush(email1);
    mb.mvPush(email3);
    mb.mvPush(email4);
    mb.mvPush(email5);


    Show(mb);
    std::cout<<std::endl;

    mb.SortWho();
    Show(mb);
    std::cout<<std::endl;

    mb.SortDate();
    Show(mb);
    std::cout<<std::endl;

    mb.SortSubject();
    Show(mb);
    std::cout<<std::endl;

    /*for (const auto &mail: mb.getMailVec()) {
        std::cout <<mail;
    }
    for (const auto &mail: mb.getMailVec()) {
        std::cout <<mail;
    }
    for (const auto &mail: mb.getMailVec()) {
        std::cout <<mail;
    }*/

    return 0;
}



