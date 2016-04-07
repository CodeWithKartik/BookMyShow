#include "Slot.h"

Slot::Slot(int st[], int et[], ULI id, double ct) {
    for (register int i = 0; i < 6; i++) {
        str_time[i] = st[i];
        end_time[i] = et[i];
    }
    movieID = id;
    cost = ct;
}
Slot::Slot(const Slot &cpy) {
    const int *st = cpy.GetStrTime();
    const int *et = cpy.GetEndTime();
    for (register int i = 0; i < 6; i++) {
        str_time[i] = st[i];
        end_time[i] = et[i];
    }
    movieID = cpy.GetMovieID();
    cost = cpy.GetCost();
}
//Slot::~Slot() {
//}
std::ostream& operator<<(std::ostream& os, const Slot st) {
    os<<"Movie Showing: "<<st.GetMovieID()<<"\n";
    os<<"Start Time: ";
    for (register int i = 0; i < 6; i++) {
        os<<st.GetStrTime()[i];
        if (i == 1 || i == 3)
            os<<":";
    }
    os<<"\n";
    os<<"End Time: ";
    for (register int i = 0; i < 6; i++) {
        os<<st.GetEndTime()[i];
        if (i == 1 || i == 3)
            os<<":";
    }
    os<<"\n";
    os<<"Movie Charges: "<<st.GetCost()<<"\n";
    return os;
}
