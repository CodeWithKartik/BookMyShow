#ifndef CINEMA_H_INCLUDED
#define CINEMA_H_INCLUDED

#include<iostream>
#include <vector>
#include "StdSlot.h"
#include "StdSeatingPlan.h"

enum CinemaType {
    PVR = 0,
    INOX,
    OTHERS,
    CMCOUNT
};
typedef unsigned long int ULI;

class Cinema {
protected:
    ULI cinemaID;
    const char *name;
    const char *address;
    CinemaType type;
    bool isOperational;
    std::vector<int> nowShowing;
    std::vector<StdSlot> slots[7];
    std::vector<StdSeatingPlan> plans[7];
public:
    Cinema(const char *nm, const char *add, CinemaType ct, bool isOp = true);
    Cinema(const Cinema &cpy);
    ~Cinema();

    //Setters
    void SetCinemaID(ULI id) {cinemaID = id;}
    void SetType(CinemaType ct) {type = ct;}
    void SetIsOperational(bool op) {isOperational = op;}
    void AddMovie(int movieId) {nowShowing.push_back(movieId);}
    void SetSlot(std::vector<StdSlot> slts[]) {
        for (register int i = 0; i < 7; i++) {
            slots[i] = slts[i];
        }
    }
    void SetPlan(std::vector<StdSeatingPlan> plns[]) {
        for (register int i = 0; i < 7; i++) {
            plans[i] = plns[i];
        }
    }
    //Getters
    ULI GetCinemaID() const {return cinemaID;}
    const char *GetName() const {return name;}
    const char *GetAddress() const {return address;}
    CinemaType GetType() const {return type;}
    bool GetOpStatus() const {return isOperational;}
    std::vector<int> GetMoviesShowing() const {return nowShowing;}
    const std::vector<StdSlot> *GetSlots() const {return slots;}
    const std::vector<StdSeatingPlan> *GetPlan() const {return plans;}

    friend std::ostream& operator<<(std::ostream& os, const Cinema *cn);
};

#endif // CINEMA_H_INCLUDED
