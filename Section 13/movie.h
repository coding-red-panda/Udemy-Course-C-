/*
 * Movie Class
 * ===========
 *
 * This class represents a Movie, with the following attributes:
 *      - name      : The name of the movie.
 *      - rating    : The rating of the movie: G, PG, PG-13 or R.
 *      - watched   : How many times the movie has been watched.
 *
 * To also improve my knowledge about the C++ ecosystem,
 * this class relies on Hungarian notation for all its variables.
 */
#ifndef MOVIE_H
#define MOVIE_H

#include <string>

class Movie {
private:
    std::string m_string_name;
    std::string m_string_rating;
    unsigned int m_uWatched;

public:
    Movie(std::string string_name, std::string string_rating, unsigned int uWatched);
    Movie(const Movie &movie);
    ~Movie();

    // Getters
    [[nodiscard]] std::string getName() const;
    [[nodiscard]] std::string getRating() const;
    [[nodiscard]] unsigned int getWatched() const;

    // Setters
    void setName(std::string &string_name);
    void setRating(std::string &string_rating);
    void setWatched(unsigned int uWatched);

    // Methods
    void incrementWatched();
};

#endif //MOVIE_H
