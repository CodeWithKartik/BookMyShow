#include "LoginMgr.h"
#include "Guest.h"
#include "Member.h"
#include "Admin.h"

LoginMgr::LoginMgr(UserType utype, UserDatabase &udb) {
    //Call appropriate user type block of code.
    now_utype = utype;
    now_logging = NULL;

    switch(utype) {
    case GUEST: {
        break;
    }
    case MEMBER: {
        char uname[100], psswd[100];
        std::cin>>uname>>psswd; //Input from UI
        Member *new_member = new Member(uname, psswd);
        Member *this_member = dynamic_cast<Member*>(udb.AddUser(new_member));
        if (this_member != NULL) {
            //std::cout<<"Reward points of "<<this_member->GetName()<<" are: "<<this_member->GetRewardPoints()<<std::endl;
            //this_member->ChangePassword(this_member->GetPsswd(), "IAmMember");
        }
        now_logging = this_member;
        break;
    }
    case ADMIN: {
        char psswd[100];
        std::cin>>psswd;    //Input from UI
        Admin *admin = new Admin(psswd);
        Admin *this_admin = dynamic_cast<Admin*>(udb.AddUser(admin));
        if (this_admin != NULL) {
            this_admin->UpdateUserDatabase(this_admin->GetName(), "IAmAdmin", udb);
            this_admin->ChangePassword("HereIsAdmin", "HereIsAdmin");
        }
        now_logging = this_admin;
        break;
    }
    default: {
       std::cout<<"Unknown user\n";
    }
    }
}
