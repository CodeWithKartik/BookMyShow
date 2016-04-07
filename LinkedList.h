#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED

#include <iostream>
#include "User.h"
#include "Movie.h"
#include "Cinema.h"

template <class DataType> class BMSLink {
protected:
    DataType *link;
    BMSLink *next;
public:
    BMSLink(DataType *ele);
    BMSLink(const BMSLink &cpy);
    ~BMSLink();
    //Getters
    DataType *GetLink() const {return link;}
    BMSLink *GetNext() const {return next;}
    //Setters
    void SetNext(BMSLink *n) {next = n;}

    friend std::ostream& operator<<(std::ostream& os, const BMSLink<User> *lnk);
    friend std::ostream& operator<<(std::ostream& os, const BMSLink<Movie> *lnk);
    friend std::ostream& operator<<(std::ostream& os, const BMSLink<Cinema> *lnk);
};

template <class DataType> class BMSUsers {
protected:
    BMSLink<DataType> *start;
public:
    BMSUsers();
    BMSUsers(const BMSUsers &cpy);
    ~BMSUsers();
    //Getters
    BMSLink<DataType> *GetStart() const {return start;}
    //Setters
    void SetStart(BMSLink<DataType> *s) {start = s;}

    BMSLink<DataType> *InsertLink(BMSLink<DataType> *link);
    BMSLink<DataType> *DeleteLink(BMSLink<DataType> *link);
    friend std::ostream& operator<<(std::ostream& os, const BMSUsers<User> *usrs);
    friend std::ostream& operator<<(std::ostream& os, const BMSUsers<Movie> *mvs);
    friend std::ostream& operator<<(std::ostream& os, const BMSUsers<Cinema> *cns);
};
#endif // LINKEDLIST_H_INCLUDED
