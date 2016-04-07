#ifndef CINEMADATABASE_H_INCLUDED
#define CINEMADATABASE_H_INCLUDED

#include "LinkedList.h"
#include "Cinema.h"
#include "Admin.h"

class CinemaDatabase {
protected:
    int no_of_cinemas;
    BMSUsers<Cinema> *cinemas;

    void RemoveCinema(const ULI id);
    Cinema *FindCinema(Cinema *cn);
    Cinema *AddCinema(Cinema *cn);
    void ModifyCinema(const ULI id, Cinema *new_cinema);
public:
    CinemaDatabase();
    CinemaDatabase(const CinemaDatabase &cpy);
    ~CinemaDatabase();
    //Getters
    int GetNoOfCinemas() const {return no_of_cinemas;}
    BMSUsers<Cinema> *GetCinemaList() const {return cinemas;}
    Cinema *GetCinemaByID(ULI id) {
        BMSLink<Cinema> *temp = cinemas->GetStart();
        for (register int i = 0; i < no_of_cinemas; i++) {
            if (temp->GetLink()->GetCinemaID() == id) {
                return temp->GetLink();
            }
            temp = temp->GetNext();
        }
    }

    void PopulateDatabase(std::vector<char> file_array);
    friend void Admin::UpdateCinemaDatabase(const char id, CinemaDatabase &mdb);
    friend std::ostream& operator<<(std::ostream& os, const CinemaDatabase &mdb);
};

#endif // CINEMADATABASE_H_INCLUDED
