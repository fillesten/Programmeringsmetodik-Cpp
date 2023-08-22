//
// Created by margi on 2022-12-02.
//

#ifndef METODIK_LAB4_EMAIL_H
#define METODIK_LAB4_EMAIL_H


#include <iostream>

class Email {
private:
    std::string who;
    std::string date;
    std::string subject;
    friend struct CompWhoDateSubject;
    friend struct CompSubjectWhoDate;
    friend struct CompDateWhoSubject;
public:
    explicit Email(const std::string &vem, const std::string& datum, const std::string& vad)
    : who(vem), date(datum), subject(vad) {  }

    friend std::ostream& operator<<(std::ostream& os, const Email& mail);
};

struct CompWhoDateSubject { bool operator()(const Email& lhs, const Email& rhs); };
struct CompDateWhoSubject { bool operator()(const Email& lhs, const Email& rhs); };
struct CompSubjectWhoDate { bool operator()(const Email& lhs, const Email& rhs); };

#endif //METODIK_LAB4_EMAIL_H
