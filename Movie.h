#ifndef MOVIE_H
#define MOVIE_H
#include <string>
#include <vector>
#include "algorithm"
using namespace std;

class Movie {
private:
    string name;
    string date;
    vector<string> genres;
    float avgRating = 0.0;
    float average_gender = 0.0;
    float average_rating = 0.0;
    float total_rating = 0.0;
    float average_age = 0.0;

    float total_gender = 0.0;
    float review_count = 0.0;
    float total_age = 0.0;
public:
    Movie();
    Movie(string& n, vector<string>& g, string& d);
    string const& getName() const;
    string const& getDate() const;
    float const& getAvgRating();
    void addReview(int rating, int age, int gender);
};

#endif