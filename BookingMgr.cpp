#include <iostream>
#include "BookingMgr.h"
#include "Cinema.h"
#include "CinemaDatabase.h"

BookingMgr::BookingMgr(MovieDatabase &mdb, CinemaDatabase &cdb) {
    ULI mid, cid;
    int r,c;
    std::cin>>mid>>cid>>r>>c;
    t_mv = mdb.GetMovieByID(mid);
    t_cn = cdb.GetCinemaByID(cid);
    day = SUNDAY;
    if (t_cn != NULL) {
        std::vector<StdSeatingPlan> *splans = const_cast<std::vector<StdSeatingPlan> *>(t_cn->GetPlan());
        std::vector<StdSlot> *sslots = const_cast<std::vector<StdSlot> *>(t_cn->GetSlots());
        if (sslots != NULL && splans != NULL) {
            for (register int i = 0; i < sslots[0].size(); i++) {
                if (mid == sslots[0][i].GetMovieID()) {
                    show_ind = i;
                    t_sp = &splans[0][i];
                    t_sp->BookChairNo(r,c);
                }
            }
        t_cn->SetPlan(splans);  //Ideally this would be executed after payment manager have confirmed the payment.
                                //Also this would go on a separate thread
        }
    }
}
