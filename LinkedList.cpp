#include "LinkedList.h"
#include "User.h"
#include "Movie.h"

//BMSLink
template <class DataType> BMSLink<DataType>::BMSLink(DataType *ele) {
    link = ele;
    next = NULL;
}
template <class DataType> BMSLink<DataType>::BMSLink(const BMSLink &cpy) {
    link = new DataType(*(cpy.GetLink()));
    next = NULL;
}
template <class DataType> BMSLink<DataType>::~BMSLink() {
    delete link;
}
//BMSUsers
template <class DataType> BMSUsers<DataType>::BMSUsers() {
    start = NULL;
}
template <class DataType> BMSUsers<DataType>::BMSUsers(const BMSUsers &cpy) {
    BMSLink<DataType> *temp = cpy.GetStart();
    while (temp != NULL) {
        InsertLink(temp);
        temp = temp->GetNext();
    }
}
template <class DataType> BMSUsers<DataType>::~BMSUsers() {
    BMSLink<DataType> *temp = start;
    while (start != NULL) {
        temp = start->GetNext();
        delete start;
        start = temp;
    }
}
template <class DataType> BMSLink<DataType> *BMSUsers<DataType>::InsertLink(BMSLink<DataType> *link) {
    BMSLink<DataType> *temp = start, *prev;
    prev = temp;
    BMSLink<DataType> *new_link = link;
    if (temp == NULL)
        start = new_link;
    else {
        while (temp != NULL) {
            prev = temp;
            temp = temp->GetNext();
        }
        prev->SetNext(new_link);
    }
    return start;
}
template <class DataType> BMSLink<DataType> *BMSUsers<DataType>::DeleteLink(BMSLink<DataType> *link) {
    if (start == NULL)
        return start;
    else {
        BMSLink<DataType> *temp = start, *prev = NULL;
        while (temp != NULL) {
            if (temp == link) {
                if (prev == NULL)
                    start = temp->GetNext();
                else {
                    prev->SetNext(temp->GetNext());
                }
                delete temp;
                break;
            }
            prev = temp;
            temp = temp->GetNext();
        }
        return start;
    }
}
std::ostream& operator<<(std::ostream& os, const BMSLink<User> *lnk) {
    os<<lnk->GetLink();
    return os;
}
std::ostream& operator<<(std::ostream& os, const BMSLink<Movie> *lnk) {
    os<<lnk->GetLink();
    return os;
}
std::ostream& operator<<(std::ostream& os, const BMSLink<Cinema> *lnk) {
    os<<lnk->GetLink();
    return os;
}
std::ostream& operator<<(std::ostream& os, const BMSUsers<User> *usrs) {
    BMSLink<User> *temp = usrs->GetStart();
    while (temp != NULL) {
        os<<"----------User Starts----------\n";
        os<<temp;
        os<<"----------User Ends------------\n";
        temp = temp->GetNext();
    }
    return os;
}
std::ostream& operator<<(std::ostream& os, const BMSUsers<Movie> *mvs) {
    BMSLink<Movie> *temp = mvs->GetStart();
    while (temp != NULL) {
        os<<"----------Movie Starts----------\n";
        os<<temp;
        os<<"----------Movie Ends------------\n";
        temp = temp->GetNext();
    }
    return os;
}
std::ostream& operator<<(std::ostream& os, const BMSUsers<Cinema> *cns) {
    BMSLink<Cinema> *temp = cns->GetStart();
    while (temp != NULL) {
        os<<"----------Cinema Starts----------\n";
        os<<temp;
        os<<"----------Cinema Ends------------\n";
        temp = temp->GetNext();
    }
    return os;
}

//Template types to be used in this project
template class BMSLink<User>;
template class BMSUsers<User>;
template class BMSLink<Movie>;
template class BMSUsers<Movie>;
template class BMSLink<Cinema>;
template class BMSUsers<Cinema>;
