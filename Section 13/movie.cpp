#include "movie.h"

#include <utility>

// Constructor
//
// Takes the following arguments:
//  - string_name: The name of the movie as string
//  - string_rating: The rating of the movie as string
//  - uWatched: unsigned integer, representing how many times the movie has been watched
//
// The constructor uses the std::move function to move the string references and prevent unneeded
// copies. This falls under the move-semantics and was recommended by CLion.
Movie::Movie(std::string string_name, std::string string_rating, const unsigned int uWatched) :
 m_string_name { std::move(string_name) }, m_string_rating { std::move(string_rating) }, m_uWatched { uWatched } {
}

Movie::Movie(const Movie& movie) : Movie(movie.m_string_name, movie.m_string_rating, movie.m_uWatched) { }

Movie::~Movie() = default;

std::string Movie::getName() const {
 return this->m_string_name;
}

std::string Movie::getRating() const {
 return this->m_string_rating;
}

unsigned int Movie::getWatched() const {
 return this->m_uWatched;
}

void Movie::setName(std::string &string_name) {
 this->m_string_name = std::move(string_name);
}

void Movie::setRating(std::string &string_rating) {
 this->m_string_rating = std::move(string_rating);
}

void Movie::setWatched(const unsigned int uWatched) {
 this->m_uWatched = uWatched;
}

void Movie::incrementWatched() {
 this->m_uWatched += 1;
}
