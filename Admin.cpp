#include "Admin.h"

class UserDatabase;

Admin::Admin(char *psswd):User(AdminName, psswd) {
    //do nothing
}
Admin::Admin(const Admin &cpy):User(cpy) {
    //do nothing
}
Admin::~Admin() {
    //do nothing
}

