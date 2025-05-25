#include "movies.h"

#include <algorithm>
#include <iostream>
#include <bits/ostream.tcc>

Movies::Movies() : m_vectorMovies { new std::vector<Movie*> } { }

Movies::~Movies() {
    delete m_vectorMovies;
}

// Returns a boolean indicating whether a Movie with the given name has already been
// added to the internal list.
// This method uses a C++11 lambda to peek into the internal vector and return true
// if a Movie object with the matching name is already present.
bool Movies::alreadyAdded(const Movie * const pMovieObject) const {
    const auto it = std::ranges::find_if(
        this->m_vectorMovies->begin(),
        this->m_vectorMovies->end(),
        [pMovieObject](const Movie* obj) { return obj->getName() == pMovieObject->getName(); }
    );

    return it != this->m_vectorMovies->end();
}


bool Movies::addMovie(Movie * pMovieObject) const {
    if (this->alreadyAdded(pMovieObject)) {
        std::cout << "Movie: \"" << pMovieObject->getName() << "\" already exists in the list." << std::endl;
        return false;
    }

    this->m_vectorMovies->push_back(pMovieObject);
    return true;
}

void Movies::incrementWatched(const std::string &string_movieName) const {
    const auto it = std::ranges::find_if(
    this->m_vectorMovies->begin(),
    this->m_vectorMovies->end(),
    [&string_movieName](const Movie* obj) { return obj->getName() == string_movieName; }
    );

    // Didn't find the required movie, so return
    if (it == this->m_vectorMovies->end()) return;

    // Increase the counter
    (*it)->incrementWatched();
}

void Movies::listMovies() const {
    std::cout << std::endl << "Movies currently tracked:" << std::endl;
    std::cout << "Name - Rating - Watched" << std::endl;

    for (auto const &movie : *this->m_vectorMovies) {
        std::cout << movie->getName() << " - " << movie->getRating() << " - " << movie->getWatched() << std::endl;
    }
}
