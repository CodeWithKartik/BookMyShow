#include "CinemaDatabase.h"

CinemaDatabase::CinemaDatabase() {
    no_of_cinemas = 0;
    cinemas = new BMSUsers<Cinema>();
}
CinemaDatabase::CinemaDatabase(const CinemaDatabase &cpy) {
    cinemas = new BMSUsers<Cinema>(*(cpy.GetCinemaList()));
}
CinemaDatabase::~CinemaDatabase() {
    delete cinemas;
}
void CinemaDatabase::RemoveCinema(const ULI id) {
    BMSLink<Cinema> *t = cinemas->GetStart();
    while (t != NULL) {
        if (t->GetLink()->GetCinemaID() == id) {
            cinemas->SetStart(cinemas->DeleteLink(t));
            no_of_cinemas--;
            break;
        }
        t = t->GetNext();
    }
}
Cinema *CinemaDatabase::FindCinema(Cinema *cn) {
    BMSLink<Cinema> *t = cinemas->GetStart();
    while (t != NULL) {
        if (t->GetLink()->GetCinemaID() == cn->GetCinemaID()) {
            return t->GetLink();
        }
        t = t->GetNext();
    }
}
void CinemaDatabase::ModifyCinema(const ULI id, Cinema *new_cinema) {
    BMSLink<Cinema> *nc;
    BMSLink<Cinema> *t = cinemas->GetStart();
    BMSLink<Cinema> *p = t;
    while (t != NULL) {
        if (t->GetLink()->GetCinemaID() == id) {
            break;
        }
        p = t;
        t = t->GetNext();
    }
    if (p == t) {
        nc = new BMSLink<Cinema>(new_cinema);
        nc->SetNext(t->GetNext());
        cinemas->SetStart(nc);
        delete t;
    } else {
        nc = new BMSLink<Cinema>(new_cinema);
        p->SetNext(nc);
        if (t != NULL) {
            nc->SetNext(t->GetNext());
            delete t;
        }
    }
}
Cinema *CinemaDatabase::AddCinema(Cinema *cn) {
    Cinema *tmp = FindCinema(cn);
    if (tmp == NULL) {
        BMSLink<Cinema> *t = new BMSLink<Cinema>(cn);
        cinemas->SetStart(cinemas->InsertLink(t));

        t->GetLink()->SetCinemaID(no_of_cinemas);
        tmp = FindCinema(cn);
        no_of_cinemas++;
    }else {
        if (tmp->GetCinemaID() != cn->GetCinemaID()) {
            std::cout<<"Sorry: This movie identity is incorrect. Please try again!\n";
            return NULL;
        }
    }
    return tmp;
}
void CinemaDatabase::PopulateDatabase(std::vector<char> file_array) {
    //Do this later;
}
void Admin::UpdateCinemaDatabase(const char id, CinemaDatabase &mdb) {
    //Ask the admin what he wants to update
    Cinema *ncinema = new Cinema("Prithvi", "Juhu Mumbai", INOX);
    std::vector<StdSlot> slts[7];
    std::vector<StdSeatingPlan> plns[7];
    double BASE = 100.0;
    for (register int i = 0; i < 7; i++) {
        int st[6] = {1,4,2,0,1,3};
        int et[6] = {1,7,1,2,4,5};
        ULI mid = i;
        double cst = BASE*(1+i/2);
        StdSlot ts(st, et, mid, cst);
        slts[i].push_back(ts);

        StdSeatingPlan ssp(2,7);
        ssp.BookChairNo(i/4,i);
        plns[i].push_back(ssp);
    }
    ncinema->SetSlot(slts);
    ncinema->SetPlan(plns);

    mdb.AddCinema(ncinema);
}
std::ostream& operator<<(std::ostream& os, const CinemaDatabase &mdb) {
    os<<"--------------------CINEMAS DATABASE STARTS--------------------\n";
    os<<"Cinema count: "<<mdb.GetNoOfCinemas()<<"\n\n";
    os<<mdb.GetCinemaList()<<"\n";
    os<<"--------------------CINEMAS DATABASE ENDS----------------------\n";
    return os;
}
