//
// Created by redpanda on 7/6/2025.
//

#ifndef SONG_H
#define SONG_H

#include <string>

class Song {
    friend std::ostream &operator<<(std::ostream &os, const Song &s);

    std::string name;
    std::string artist;
    int rating{};

public:
    Song() = default;

    Song(std::string name, std::string artist, const int rating)
        : name{std::move(name)}, artist{std::move(artist)}, rating{rating} {
    }

    std::string get_name() const;
    std::string get_artist() const;
    int get_rating() const;

    bool operator<(const Song &rhs) const;
    bool operator==(const Song &rhs) const;
};

#endif //SONG_H
