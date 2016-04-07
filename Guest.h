#ifndef GUEST_H_INCLUDED
#define GUEST_H_INCLUDED

#include <iostream>
#include "User.h"

static const char GuestName[] = "GUEST";
class Guest : public User {
protected:
public:
    Guest();
    virtual void ChangePassword(const char *old_psswd, const char *new_psswd);
};
#endif // GUEST_H_INCLUDED
