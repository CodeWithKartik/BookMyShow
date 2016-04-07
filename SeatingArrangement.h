#ifndef SEATINGARRANGEMENT_H_INCLUDED
#define SEATINGARRANGEMENT_H_INCLUDED

#include <iostream>

class SeatingArrangement {
protected:
    int nrows;
    int ncols;
    bool **chairs;
public:
    SeatingArrangement(int nr, int nc);
    SeatingArrangement(const SeatingArrangement &cpy);
    virtual ~SeatingArrangement();
    //Setters
    void SetRows(int nr) {nrows = nr;}
    void SetCols(int nc) {ncols = nc;}
    //Getters
    int GetRows() const {return nrows;}
    int GetCols() const {return ncols;}
    bool GetChairs(int i, int j) const {return chairs[i][j];}

    bool& operator()(const int i, const int j);
    void BookChairNo(int i, int j);

    friend std::ostream& operator<<(std::ostream& os, const SeatingArrangement sa);
};

#endif // SEATINGARRANGEMENT_H_INCLUDED
