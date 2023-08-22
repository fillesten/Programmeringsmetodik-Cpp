//
// Created by margi on 2022-12-06.
//

#ifndef METODIK_LAB4_MAILBOX_H
#define METODIK_LAB4_MAILBOX_H

#include <vector>
#include "Email.h"

class MailBox {
    std::vector<Email> MailVec;
public:

    MailBox() = default;
    //used for the range based loop
    //const std::vector<Email> &getMailVec() const;
    void mvPush(Email &mail);

    const Email* begin() const;
    const Email* end() const;

    void SortWho();
    void SortDate();
    void SortSubject();
};

#endif //METODIK_LAB4_MAILBOX_H
