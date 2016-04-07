#include "User.h"
#include "Guest.h"
#include "Member.h"
#include "Admin.h"
#include <cstring>

User::User() {
    //do nothing
}
User::User(const char *uname, char *psswd):username(std::strcpy((new char[strlen(uname)+1]), uname)) {
    password = new char[strlen(psswd)+1];
    strcpy(password, psswd);
    userID = -1;
}
User::User(const User &cpy):username(cpy.GetName()) {
    userID = cpy.GetUserID();
    password = new char[strlen(cpy.GetPsswd())+1];
    strcpy(password, cpy.GetPsswd());
}
User::~User() {
    delete[] username;
    delete[] password;
}
void User::ChangePassword(const char *old_psswd, const char *new_psswd) {
    if (strcmp(old_psswd, password) != 0)
        std::cout<<"Sorry: The password is incorrect. Please try again!\n";
    else {
        delete[] password;
        password = new char[strlen(new_psswd)+1];
        strcpy(password, new_psswd);
    }
}
bool User::IsPasswordCorrect(const char *psswd) {
    if (strcmp(psswd, password) == 0)
        return true;
    else
        return false;
}
std::ostream& operator<<(std::ostream& os, const User *usr) {
    if (dynamic_cast<const Member*>(usr))
        os<<"UserType: Member\n";
    else if (dynamic_cast<const Admin*>(usr))
        os<<"UserType: Admin\n";
    os<<"UserId: "<<usr->GetUserID()<<"\n";
    os<<"User name: "<<usr->GetName()<<"\n";
    os<<"Password: "<<usr->GetPsswd()<<"\n";
    if (dynamic_cast<const Member*>(usr))
        os<<"Reward points: "<<(dynamic_cast<const Member*>(usr))->GetRewardPoints()<<"\n";
    return os;
}
