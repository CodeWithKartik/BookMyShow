#include "Cinema.h"
#include <cstring>

Cinema::Cinema(const char *nm, const char *add, CinemaType ct, bool isOp)
:name(std::strcpy((new char[strlen(nm)+1]), nm)), address(std::strcpy((new char[strlen(add)+1]), add)) {
    cinemaID = -1;
    type = ct;
    isOperational = isOp;
    nowShowing.clear();
    for (register int i = 0; i < 7; i++) {
        slots[i].clear();
        plans[i].clear();
    }
}
Cinema::Cinema(const Cinema &cpy):name(cpy.GetName()), address(cpy.GetAddress()) {
    cinemaID = cpy.GetCinemaID();
    type = cpy.GetType();
    isOperational = cpy.GetOpStatus();
    nowShowing = cpy.GetMoviesShowing();
    const std::vector<StdSlot> *slts = cpy.GetSlots();
    const std::vector<StdSeatingPlan> *plns = cpy.GetPlan();
    for (register int i = 0; i < 7; i++) {
        slots[i] = slts[i];
        plans[i] = plns[i];
    }
}
Cinema::~Cinema() {
    delete[] name;
    delete[] address;
}
std::ostream& operator<<(std::ostream& os, const Cinema *cn) {
    os<<"CinemaId: "<<cn->GetCinemaID()<<"\n";
    os<<"Name: "<<cn->GetName()<<"\n";
    os<<"Address: "<<cn->GetAddress()<<"\n";
    if (cn->GetType() == 0)
        os<<"Type: PVR"<<"\n";
    else if (cn->GetType() == 1)
        os<<"Type: INOX"<<"\n";
    else
        os<<"Type: OTHERS"<<"\n";
    os<<"Is Operational: "<<cn->GetOpStatus()<<"\n";
    /*os<<"Now Showing: ";
    for (register int i = 0; i < cn->GetMoviesShowing().size(); i++) {
        //os<<cn->GetMoviesShowing()[i].Get
    }
    os<<"\n";*/
    for (register int i = 0; i < 7; i++)
        for (register int j = 0; j < cn->GetSlots()[i].size(); j++)
            os<<cn->GetSlots()[i][j]<<"\n";
    for (register int i = 0; i < 7; i++)
        for (register int j = 0; j < cn->GetPlan()[i].size(); j++)
            os<<cn->GetPlan()[i][j]<<"\n";
    return os;
}
