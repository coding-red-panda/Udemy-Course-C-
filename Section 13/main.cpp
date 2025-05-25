#include <iostream>
#include "movie.h"
#include "movies.h"

using namespace std;

int main() {
    const auto pMoviesList = new Movies();

    // Create three movies to use as reference
    const auto pMovieDieHard = new Movie("Die Hard", "G", 1);
    const auto pMovieMadMax = new Movie("Mad Max", "R", 2);
    const auto pMovieRobocop = new Movie("Robocop", "G", 3);
    const auto pMovieDuplicate = new Movie(*pMovieRobocop);

    // Add the movies to the list.
    cout << boolalpha << endl;
    cout << "Adding \"" << pMovieDieHard->getName() << "\" Movie: " << pMoviesList->addMovie(pMovieDieHard) << endl;
    cout << "Adding \"" << pMovieMadMax->getName() << "\" Movie: " << pMoviesList->addMovie(pMovieMadMax) << endl;
    cout << "Adding \"" << pMovieRobocop->getName() << "\" Movie: " << pMoviesList->addMovie(pMovieRobocop) << endl;

    // Verify alreadyAdded method
    cout << endl;
    cout << "\"Die Hard\" already added? " << pMoviesList->alreadyAdded(pMovieDieHard) << endl;
    cout << "\"Mad Max\" already added? " << pMoviesList->alreadyAdded(pMovieMadMax) << endl;
    cout << "\"Robocop\" already added? " << pMoviesList->alreadyAdded(pMovieRobocop) << endl;

    // Try adding a movie already present
    pMoviesList->addMovie(pMovieDuplicate);

    // Increment the watched for each movie
    pMoviesList->incrementWatched(pMovieDieHard->getName());
    pMoviesList->incrementWatched(pMovieMadMax->getName());
    pMoviesList->incrementWatched(pMovieRobocop->getName());

    // Display all movies, should list them with watched as 2-3-4
    pMoviesList->listMovies();

    // Cleanup
    delete pMovieDieHard;
    delete pMovieMadMax;
    delete pMovieRobocop;
    delete pMovieDuplicate;
    delete pMoviesList;
}
