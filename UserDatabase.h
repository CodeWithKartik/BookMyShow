#ifndef USERDATABASE_H_INCLUDED
#define USERDATABASE_H_INCLUDED

#include <iostream>
#include <vector>
#include "User.h"
#include "LinkedList.h"
#include "Admin.h"

typedef unsigned long int ULI;
class UserDatabase {
protected:
    ULI user_count;
    BMSUsers<User> *database;

    void RemoveUser(const char *username);
    User *FindUser(User *usr);
    void ModifyUser(const char *username, char *new_psswd);
public:
    UserDatabase();
    UserDatabase(const UserDatabase &cpy);
    ~UserDatabase();

    //Getters
    BMSUsers<User> *GetDatabase() const {return database;}
    ULI GetUserCount() const {return user_count;}
    User *AddUser(User *usr);

    void PopulateDatabase(std::vector<char> file_array);

    friend void Admin::UpdateUserDatabase(const char *username, char *new_psswd, UserDatabase &obj);
    friend std::ostream& operator<<(std::ostream& os, const UserDatabase &udb);
};
#endif // USERDATABASE_H_INCLUDED
