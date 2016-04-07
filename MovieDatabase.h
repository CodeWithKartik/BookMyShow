#ifndef MOVIEDATABASE_H_INCLUDED
#define MOVIEDATABASE_H_INCLUDED

#include <vector>
#include "Movie.h"
#include "LinkedList.h"
#include "Admin.h"

class MovieDatabase {
protected:
    int no_of_movies;
    BMSUsers<Movie> *movies;

    void RemoveMovie(const ULI id);
    Movie *FindMovie(Movie *mv);
    Movie *AddMovie(Movie *mv);
    void ModifyMovie(const ULI id, Movie *new_movie);
public:
    MovieDatabase();
    MovieDatabase(const MovieDatabase &cpy);
    ~MovieDatabase();
    //Getters
    int GetNoOfMovies() const {return no_of_movies;}
    BMSUsers<Movie> *GetMovieList() const {return movies;}
    Movie *GetMovieByID(ULI id) {
        BMSLink<Movie> *temp = movies->GetStart();
        for (register int i = 0; i < no_of_movies; i++) {
            if (temp->GetLink()->GetID() == id) {
                return temp->GetLink();
            }
            temp = temp->GetNext();
        }
    }

    void PopulateDatabase(std::vector<char> file_array);
    friend void Admin::UpdateMovieDatabase(const char id, MovieDatabase &mdb);
    friend std::ostream& operator<<(std::ostream& os, const MovieDatabase &mdb);
};

#endif // MOVIEDATABASE_H_INCLUDED
