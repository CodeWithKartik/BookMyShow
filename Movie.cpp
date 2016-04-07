#include "Movie.h"
#include <cstring>

Movie::Movie(const char *mname, char *lang, MovieType cat):name(std::strcpy((new char[strlen(mname)+1]), mname)) {
    language = new char[strlen(lang)+1];
    strcpy(language, lang);
    category = cat;
    relDate[0] = 0; relDate[1] = 0;
    inCinemas.clear();
    movieID = -1;
}
Movie::Movie(const Movie &cpy):name(cpy.GetName()) {
    movieID = cpy.GetID();
    language = new char[strlen(cpy.GetLanguage())+1];
    strcpy(language, cpy.GetLanguage());
    for (register int i = 0; i < 8; i++) {
        const int *temp = cpy.GetRelDate();
        relDate[i] = temp[i];
    }
    category = cpy.GetCategory();
    inCinemas = cpy.GetCinemaList();
}
Movie::~Movie() {
    delete[] name;
    delete[] language;
}
std::ostream& operator<<(std::ostream& os, const Movie *mv) {
    os<<"MovieId: "<<mv->GetID()<<"\n";
    os<<"Name: "<<mv->GetName()<<"\n";
    os<<"Language: "<<mv->GetLanguage()<<"\n";
    if (mv->GetCategory() == 0)
        os<<"Category: U"<<"\n";
    else if (mv->GetCategory() == 1)
        os<<"Category: A"<<"\n";
    else
        os<<"Category: UA"<<"\n";
    os<<"Releasing on: ";
    for (register int i = 0; i < 8; i++) {
        os<<mv->GetRelDate()[i];
        if (i == 1 || i == 3)
            os<<"/";
    }
    os<<"\n";
    /*os<<"Now showing in: ";
    for (register int i = 0; i < mv->GetCinemaList().size(); i++) {
        //Find names of cinemas from here.
    }*/
    return os;
}
/*
void Movie::UpdateMovieInformation(ULI id, char *lang, int rDate[], MovieType cat) {
    if (id != movieID) {
        std::cout<<"Sorry: This movie identity is incorrect. Please try again!\n";
    } else {
        delete[] language;
        language = new char[strlen(lang)+1];
        strcpy(language, lang);
        for (register int i = 0; i < 8; i++) {
            relDate[i] = rDate[i];
        }
        category = cat;
    }
}
void Movie::UpdatePlayingInCinemasList(ULI id, std::vector<ULI> inCinemas) {

}
*/
