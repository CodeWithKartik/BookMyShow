#ifndef LOGINMGR_H_INCLUDED
#define LOGINMGR_H_INCLUDED

#include <iostream>
#include "User.h"
#include "UserDatabase.h"

class LoginMgr {
protected:
    //Ideally these two variables should be on the UI side
    User *now_logging;
    UserType now_utype;
public:
    LoginMgr(UserType utype, UserDatabase &udb);
    //Getters
    User *GetNowLogged() const {return now_logging;}
    UserType GetType() const {return now_utype;}
};
#endif // LOGINMGR_H_INCLUDED
