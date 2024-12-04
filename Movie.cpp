#include "Movie.h"

Movie::Movie() {
    name = "";
    date = "";
    avgRating = -1;
    genres = {};
}

Movie::Movie(string& n, vector<string>& g, string& d) {
    name = n;
    genres = g;
    date = d;
}

string const& Movie::getName() const {
    return name;
}

string const& Movie::getDate() const {
    return date;
}

double const& Movie::getAvgRating() const {
    return avgRating;
}

void Movie::addReview(int rating, int age, int gender)
{
    ++review_count;

    // Calculate cumulative total
    total_rating += rating;
    average_rating = total_rating / review_count;

    total_age += age;
    average_age = total_age / review_count;

    total_gender += gender;
    average_gender = total_gender / review_count;
}