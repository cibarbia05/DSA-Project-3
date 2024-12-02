#ifndef MOVIE_H
#define MOVIE_H

#include <string>
#include "algorithm"

using namespace std;

class Movie {
private:
    string title;
    string date;
    double avgRating;
public:
    Movie();
    Movie(string& t, string& d, double a);
    string const& getTitle() const;
    string const& getDate() const;
    double const& getAvgRating() const;
};

#endif