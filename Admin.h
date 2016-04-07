#ifndef ADMIN_H_INCLUDED
#define ADMIN_H_INCLUDED

#include <iostream>
#include "User.h"
#include "Cinema.h"
#include "Movie.h"

class UserDatabase;
class MovieDatabase;
class CinemaDatabase;

static const char AdminName[] = "ADMIN";
class Admin : public User {
public:
    Admin(char *psswd);
    Admin(const Admin &cpy);
    ~Admin();

    void UpdateUserDatabase(const char *username, char *new_psswd, UserDatabase &obj);
    void UpdateMovieDatabase(const char id, MovieDatabase &mdb);
    void UpdateCinemaDatabase(const char id, CinemaDatabase &mdb);
};
#endif // ADMIN_H_INCLUDED
