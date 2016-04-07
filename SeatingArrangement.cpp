#include "SeatingArrangement.h"

SeatingArrangement::SeatingArrangement(int nr, int nc) {
    nrows = nr;
    ncols = nc;
    chairs = new bool*[nr];
    for (register int i = 0; i < nr; i++) {
        chairs[i] = new bool[nc];
        for (register int j = 0; j < nc; j++)
            chairs[i][j] = false;
    }
}
SeatingArrangement::SeatingArrangement(const SeatingArrangement &cpy) {
    nrows = cpy.GetRows();
    ncols = cpy.GetCols();
    chairs = new bool*[nrows];
    for (register int i = 0; i < nrows; i++) {
        chairs[i] = new bool[ncols];
        for (register int j = 0; j < ncols; j++)
            chairs[i][j] = cpy.GetChairs(i,j);
    }
}
SeatingArrangement::~SeatingArrangement() {
    for (register int i = 0; i < nrows; i++)
        delete[] chairs[i];
    delete[] chairs;
}
bool &SeatingArrangement::operator()(const int i, const int j) {
    if ((i < nrows && i >= 0) && (j < ncols && j >= 0))
        return chairs[i][j];
    else {
        static bool dummy = false;
        return dummy;
    }
}
void SeatingArrangement::BookChairNo(int i, int j) {
    (*this)(i,j) = true;
}
std::ostream& operator<<(std::ostream& os, const SeatingArrangement sa) {
    for (register int i = 0; i < sa.GetRows(); i++) {
        for (register int j = 0; j < sa.GetCols(); j++) {
            os<<sa.GetChairs(i,j);
        }
        os<<"\n";
    }
    return os;
}
