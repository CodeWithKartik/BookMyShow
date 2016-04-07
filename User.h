#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED

#include <iostream>
#include <cstring>

enum UserType {
    GUEST = 0,
    MEMBER,
    ADMIN,
    COUNT
};

class User {
protected:
    long int userID;
    const char *username;
    char *password;
public:
    User();
    User(const char *uname, char *psswd);
    User(const User &cpy);
    virtual ~User();
    //Getters
    const long int GetUserID() const {return userID;}
    const char *GetName() const {
        return username;}
    char *GetPsswd() const {return password;}
    //Setters
    void SetUserID(long int uid) {userID = uid;}
    void SetPsswd(char *psswd) {
        password = psswd;
    }

    virtual void ChangePassword(const char *old_psswd, const char *new_psswd);
    bool IsPasswordCorrect(const char *psswd);
    friend std::ostream& operator<<(std::ostream& os, const User *usr);
};
#endif // USER_H_INCLUDED
