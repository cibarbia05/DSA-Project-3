#include "Movie.h"

Movie::Movie() {
    title = "";
    date = "";
    avgRating = -1;
}

Movie::Movie(string& t, string& d, double a) {
    title = t;
    date = d;
    avgRating = a;
}

string const& Movie::getTitle() const {
    return title;
}

string const& Movie::getDate() const {
    return date;
}

double const& Movie::getAvgRating() const {
    return avgRating;
}