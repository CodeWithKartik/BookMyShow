#include "MovieDatabase.h"

MovieDatabase::MovieDatabase() {
    no_of_movies = 0;
    movies = new BMSUsers<Movie>();
}
MovieDatabase::MovieDatabase(const MovieDatabase &cpy) {
    movies = new BMSUsers<Movie>(*(cpy.GetMovieList()));
}
MovieDatabase::~MovieDatabase() {
    delete movies;
}
void MovieDatabase::RemoveMovie(const ULI id) {
    BMSLink<Movie> *t = movies->GetStart();
    while (t != NULL) {
        if (t->GetLink()->GetID() == id) {
            movies->SetStart(movies->DeleteLink(t));
            no_of_movies--;
            break;
        }
        t = t->GetNext();
    }
}
Movie *MovieDatabase::FindMovie(Movie *mv) {
    BMSLink<Movie> *t = movies->GetStart();
    while (t != NULL) {
        if (t->GetLink()->GetID() == mv->GetID()) {
            return t->GetLink();
        }
        t = t->GetNext();
    }
}
void MovieDatabase::ModifyMovie(const ULI id, Movie *new_movie) {
    BMSLink<Movie> *nm;
    BMSLink<Movie> *t = movies->GetStart();
    BMSLink<Movie> *p = t;
    while (t != NULL) {
        if (t->GetLink()->GetID() == id) {
            break;
        }
        p = t;
        t = t->GetNext();
    }
    if (p == t) {
        nm = new BMSLink<Movie>(new_movie);
        nm->SetNext(t->GetNext());
        movies->SetStart(nm);
        delete t;
    } else {
        nm = new BMSLink<Movie>(new_movie);
        p->SetNext(nm);
        if (t != NULL) {
            nm->SetNext(t->GetNext());
            delete t;
        }
    }
}
Movie *MovieDatabase::AddMovie(Movie *mv) {
    Movie *tmp = FindMovie(mv);
    if (tmp == NULL) {
        BMSLink<Movie> *t = new BMSLink<Movie>(mv);
        movies->SetStart(movies->InsertLink(t));

        t->GetLink()->SetMovieID(no_of_movies);
        tmp = FindMovie(mv);
        no_of_movies++;
    }else {
        if (tmp->GetID() != mv->GetID()) {
            std::cout<<"Sorry: This movie identity is incorrect. Please try again!\n";
            return NULL;
        }
    }
    return tmp;
}
void MovieDatabase::PopulateDatabase(std::vector<char> file_array) {
    //Do this later;
}
void Admin::UpdateMovieDatabase(const char id, MovieDatabase &mdb) {
    //Ask the admin what he wants to update
    Movie *nmovie = new Movie("Sholay", "Hindi", UA);
    int arr[8] = {1, 1, 0, 8, 2, 0, 1, 5};
    nmovie->SetRelDate(arr);
    mdb.AddMovie(nmovie);
}
std::ostream& operator<<(std::ostream& os, const MovieDatabase &mdb) {
    os<<"--------------------MOVIE DATABASE STARTS--------------------\n";
    os<<"Movie count: "<<mdb.GetNoOfMovies()<<"\n\n";
    os<<mdb.GetMovieList()<<"\n";
    os<<"--------------------MOVIE DATABASE ENDS----------------------\n";
    return os;
}
