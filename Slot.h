#ifndef SLOT_H_INCLUDED
#define SLOT_H_INCLUDED

#include <iostream>
typedef unsigned long int ULI;

class Slot {
protected:
    int str_time[6];
    int end_time[6];
    ULI movieID;
    double cost;
public:
    Slot(int st[], int et[], ULI id, double ct);
    Slot(const Slot &cpy);
    //virtual ~Slot();
    //Setters
    void SetStrTime(int st[]) {
        for(register int i = 0; i < 6; i++)
            str_time[i] = st[i];
    }
    void SetEndTime(int et[]) {
        for(register int i = 0; i < 6; i++)
            end_time[i] = et[i];
    }
    void SetMovieId(ULI id) {movieID = id;}
    void SetCost(double ct) {cost = ct;}
    //Getters
    const int *GetStrTime() const {return str_time;}
    const int *GetEndTime() const {return end_time;}
    const ULI GetMovieID() const {return movieID;}
    const double GetCost() const {return cost;}

    friend std::ostream& operator<<(std::ostream& os, const Slot st);
};


#endif // SLOT_H_INCLUDED
