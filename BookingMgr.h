#ifndef BOOKINGMGR_H_INCLUDED
#define BOOKINGMGR_H_INCLUDED

#include "Movie.h"
#include "Cinema.h"
#include "MovieDatabase.h"
#include "CinemaDatabase.h"

enum WeekDays {
    SUNDAY = 0,
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY
};

class BookingMgr {
protected:
    //Ideally these variables should be stored on the UI side
    Movie *t_mv;
    Cinema *t_cn;
    WeekDays day;
    int show_ind;
    StdSeatingPlan *t_sp;
public:
    BookingMgr(MovieDatabase &mdb, CinemaDatabase &cdb);
};

#endif // BOOKINGMGR_H_INCLUDED
