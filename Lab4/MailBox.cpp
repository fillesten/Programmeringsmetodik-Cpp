//
// Created by margi on 2022-12-06.
//

#include <algorithm>
#include "MailBox.h"
const std::vector<Email> &MailBox::getMailVec() const {
    return MailVec;
}

void MailBox::mvPush(Email &mail){
    MailVec.push_back(mail);
}


const Email* MailBox::begin() const {
    return &MailVec[0];
}
const Email* MailBox::end() const {
    return begin() + MailVec.size();
}




void MailBox::SortWho() {
        std::sort(MailVec.begin(),MailVec.end(), CompWhoDateSubject());
}
void MailBox::SortDate() {
    std::sort(MailVec.begin(),MailVec.end(), CompDateWhoSubject());
}
void MailBox::SortSubject() {
    std::sort(MailVec.begin(),MailVec.end(), CompSubjectWhoDate());
}






