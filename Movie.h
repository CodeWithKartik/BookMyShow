#ifndef MOVIE_H_INCLUDED
#define MOVIE_H_INCLUDED

#include <iostream>
#include <vector>
#include <cstring>

enum MovieType {
    U = 0,
    A,
    UA,
    MTCOUNT
};
typedef unsigned long int ULI;

class Movie {
protected:
    ULI movieID;
    const char *name;
    char *language;
    int relDate[8];
    MovieType category;
    std::vector<ULI> inCinemas;
public:
    Movie(const char *mname, char *lang, MovieType cat);
    Movie(const Movie &cpy);
    ~Movie();
    //Getters
    const ULI GetID() const {return movieID;}
    const char *GetName() const {return name;}
    const char *GetLanguage() const {return language;}
    const int *GetRelDate() const {return relDate;}
    const MovieType GetCategory() const {return category;}
    const std::vector<ULI> GetCinemaList() const {return inCinemas;}

    //Setters
    void SetMovieID(const ULI id) {movieID = id;}
    void SetLanguage(char *lang) {
        language = new char[strlen(lang)+1];
        strcpy(language, lang);
    }
    void SetRelDate(int relDt[]) {
        for (register int i = 0; i < 8; i++)
            relDate[i] = relDt[i];
    }
    void SetCategory(MovieType cat) {category = cat;}
    void SetCinemaList(std::vector<ULI> cineLst) {inCinemas = cineLst;}


    friend std::ostream& operator<<(std::ostream& os, const Movie *mv);
    //void UpdateMovieInformation(ULI id, char *lang, int rDate[], MovieType cat);
    //void UpdatePlayingInCinemasList(ULI id, std::vector<ULI> inCinemas);
};

#endif // MOVIE_H_INCLUDED
