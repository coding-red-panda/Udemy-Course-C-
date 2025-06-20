// Section 19
// Challenge 1
// Formatting output
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

struct City {
    std::string name;
    long population;
    double cost;
};

// Assume each country has at least 1 city
struct Country {
    std::string name;
    std::vector<City> cities;
};

struct Tours {
    std::string title;
    std::vector<Country> countries;
};

constexpr int FIXED_LENGTH = 70;

void display_title(const std::string &title) {
    const int width = (FIXED_LENGTH - title.length()) / 2;

    std::cout << std::setw(width) << ' ';
    std::cout << std::setw(0) << title << std::endl;
    std::cout << std::endl;
    std::cout << std::setw(20) << std::left << "Country";
    std::cout << std::setw(25) << std::left << "City";
    std::cout << std::setw(10) << std::right << "Population";
    std::cout << std::setw(15) << std::right << "Price";
    std::cout << std::setw(width) << ' ' << std::setw(0) << std::endl;
}

void display_line() {
    std::cout << std::setw(FIXED_LENGTH) << std::setfill('-') << '-';
    std::cout << std::setfill(' ') << std::endl;
}

void display_city(const Country &country, const City &city) {
    if (city.name != country.cities[0].name) std::cout << std::setw(20) << ' ';

    std::cout << std::setw(25) << std::left << city.name;
    std::cout << std::setw(10) << std::right << city.population;
    std::cout << std::setw(15) << std::right << std::setprecision(2) << std::fixed << city.cost << std::endl;
}

int main()
{
    Tours tours
        { "Tour Ticket Prices from Miami",
            {
                {
                    "Colombia", { 
                        { "Bogota", 8778000, 400.98 },
                        { "Cali", 2401000, 424.12 },
                        { "Medellin", 2464000, 350.98 },
                        { "Cartagena", 972000, 345.34 } 
                    },
                },
                {
                    "Brazil", { 
                        { "Rio De Janiero", 13500000, 567.45 },
                        { "Sao Paulo", 11310000, 975.45 },
                        { "Salvador", 18234000, 855.99 }
                    },
                },
                {
                    "Chile", { 
                        { "Valdivia", 260000, 569.12 }, 
                        { "Santiago", 7040000, 520.00 }
                },
            },
                { "Argentina", { 
                    { "Buenos Aires", 3010000, 723.77 } 
                } 
            },
        }
    };


    display_title(tours.title);
    display_line();

    for(auto country : tours.countries) {   // loop through the countries
        // We reserve the first 20 spaces for the country:
        std::cout << std::setw(20) << std::left << country.name;

        // Loop over the cities, and display them accordingly, keeping in mind
        // that the first record needs to be offset by the city already.
        for(auto city : country.cities) {
            display_city(country, city);
        }
    }

    std::cout << std::endl << std::endl;
    return 0;
}