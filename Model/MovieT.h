#ifndef DSAPROJECT3_MOVIET_H
#define DSAPROJECT3_MOVIET_H
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class MovieT{
private:
    int movieId;
    string title;
    string releaseDate;
    string imdbUrl;
    vector<std::string> genres;
public:
    MovieT(int id, const string& movieTitle, const string& release,
           const string& url, const vector<int>& genreFlags);
    int getMovieId() const;
    string getTitle() const;
    string getReleaseDate() const;
    string getImdbUrl() const;
    std::vector<string> getGenres() const;
    void printMovie() const;
};

#endif //DSAPROJECT3_MOVIET_H