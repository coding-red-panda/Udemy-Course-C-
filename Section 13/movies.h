/*
* Movies Class
 * ============
 *
 * This class models a collection of movie objects.
 *
 * To also improve my knowledge about the C++ ecosystem,
 * this class relies on Hungarian notation for all its variables.
 */
#ifndef MOVIES_H
#define MOVIES_H

#include <vector>
#include "movie.h"

class Movies {
private:
    std::vector<Movie*> * m_vectorMovies;

public:
    Movies();
    ~Movies();

    bool alreadyAdded(const Movie * pMovieObject) const;
    bool addMovie(Movie * pMovieObject) const;
    void incrementWatched(const std::string &string_movieName) const;
    void listMovies() const;
};
#endif //MOVIES_H
