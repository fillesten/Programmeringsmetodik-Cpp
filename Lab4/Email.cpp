//
// Created by margi on 2022-12-02.
//

#include "Email.h"


bool CompWhoDateSubject::operator()(const Email &lhs, const Email &rhs) {
    if ( lhs.who != rhs.who ) { return lhs.who < rhs.who; }
    if ( lhs.date != rhs.date ) { return lhs.date < rhs.date; }
    return lhs.subject < rhs.subject;
}

bool CompDateWhoSubject::operator()(const Email &lhs, const Email &rhs) {
    if ( lhs.date != rhs.date ) { return lhs.date < rhs.date; }
    if ( lhs.who != rhs.who ) { return lhs.who < rhs.who; }
    return false;
}

bool CompSubjectWhoDate::operator()(const Email &lhs, const Email &rhs) {
    if (lhs.subject != rhs.subject) { return lhs.subject < rhs.subject; }
    if  (lhs.who != rhs.who) { return lhs.who < rhs.who; }
    return false;
}



std::ostream& operator<<(std::ostream& os, const Email& mail) {
    std::cout <<mail.who <<" Date: "<< mail.date <<
    " Subject-"<< std::endl<<mail.subject
    <<std::endl;
    return os;
}


