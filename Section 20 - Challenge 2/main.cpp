#include <iostream>
#include <list>
#include <string>
#include <cctype>
#include <iomanip>
#include <limits>
#include "Song.h"

void display_menu() {
    std::cout << "\nF - Play First Song" << std::endl;
    std::cout << "N - Play Next song" << std::endl;
    std::cout << "P - Play Previous song" << std::endl;
    std::cout << "A - Add and play a new Song at current location" << std::endl;
    std::cout << "L - List the current playlist" << std::endl;
    std::cout << "===============================================" << std::endl;
    std::cout << "Enter a selection (Q to quit): ";
}

void play_current_song(const Song &song) {
    std::cout << "Playing " << song << std::endl;
}

void display_playlist(const std::list<Song> &playlist, const Song &current_song) {
    for (auto const &song: playlist) {
        std::cout << song << std::endl;
    }

    std::cout << "Current Song: " << current_song << std::endl;
}

int main() {
    std::list<Song> playlist{
        {"God's Plan", "Drake", 5},
        {"Never Be The Same", "Camila Cabello", 5},
        {"Pray For Me", "The Weekend and K. Lamar", 4},
        {"The Middle", "Zedd, Maren Morris & Grey", 5},
        {"Wait", "Maroone 5", 4},
        {"Whatever It Takes", "Imagine Dragons", 3}
    };

    char selection;
    auto current_song = playlist.begin();

    display_playlist(playlist, *current_song);

    do {
        display_menu();

        // Read the menu selection and convert to uppercase
        std::cin >> selection;
        selection = std::toupper(selection);

        switch (selection) {
            case 'F': {
                std::cout << "Playing first Song" << std::endl;
                current_song = playlist.begin();
                play_current_song(*current_song);
            }
            case 'N': {
                std::cout << "Playing next song" << std::endl;
                ++current_song;

                // Loop around when we are at the end of the playlist
                if (current_song == playlist.end()) {
                    current_song = playlist.begin();
                }

                play_current_song(*current_song);
                break;
            }
            case 'P': {
                std::cout << "Playing previous song" << std::endl;

                // Loop around when we are at the beginning of the playlist
                if (current_song == playlist.begin()) {
                    current_song = playlist.end();
                }

                --current_song;
                play_current_song(*current_song);
                break;
            }
            case 'A': {
                std::string name, artist;
                int rating;

                // Clear the input buffer
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                std::cout << "Enter song name: ";
                std::getline(std::cin, name);
                std::cout << "Enter artist name: ";
                std::getline(std::cin, artist);
                std::cout << "Enter rating (1-5): ";
                std::cin >> rating;

                playlist.insert(current_song, Song{name, artist, rating});
                --current_song; // Move back to the newly added song
                play_current_song(*current_song);
                break;
            }
            case 'L':
                display_playlist(playlist, *current_song);
                break;
            case 'Q':
                std::cout << "Quitting" << std::endl;
                break;
            default:
                std::cout << "Illegal choice, try again...";
                break;
        }
    } while (selection != 'Q');

    std::cout << "Thanks for listening!" << std::endl;
    return 0;
}
