//
// Created by Gabriel on 12/3/2024.
//

#ifndef DSAPROJECT3_DATAPARSING_H
#define DSAPROJECT3_DATAPARSING_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <map>
#include <queue>

// Genre names constant
extern const std::vector<std::string> GENRE_NAMES;

// RatingEntry class declaration
class RatingEntry {
private:
    int userId;
    int itemId;
    int rating;

public:
    RatingEntry(int user, int item, int rate);
    int getUserId() const;
    int getItemId() const;
    int getRating() const;
    void printEntry() const;
};

// User class declaration
class User {
private:
    int userId;
    int age;
    int intGender;
    std::string gender;
    std::string occupation;
    std::string zipCode;

public:
    User(int id, int userAge, const std::string& userGender,
         const std::string& userOccupation, const std::string& userZipCode);
    int getUserId() const;
    int getAge() const;
    int getGender() const;
    std::string getOccupation() const;
    std::string getZipCode() const;
    void printUser() const;
};

// MovieT class declaration
class MovieT{
private:
    int movieId;
    std::string title;
    std::string releaseDate;
    std::string imdbUrl;
    std::vector<std::string> genres;

public:
    MovieT(int id, const std::string& movieTitle, const std::string& release,
          const std::string& url, const std::vector<int>& genreFlags);
    int getMovieId() const;
    std::string getTitle() const;
    std::string getReleaseDate() const;
    std::string getImdbUrl() const;
    std::vector<std::string> getGenres() const;
    void printMovie() const;
};

// MovieData class declaration
class MovieData {
private:
    std::string name;
    std::vector<std::string> genre;
    std::string realeaseDate;

    float average_gender = 0.0;
    float average_rating = 0.0;
    float total_rating = 0.0;
    float average_age = 0.0;

    float total_gender = 0.0;
    float review_count = 0.0;
    float total_age = 0.0;

public:
    MovieData();
    MovieData(std::string newName, std::vector<std::string> newGenre, std::string date);

    std::string get_genre() const;
    std::string get_realease_date() const;
    std::string get_name() const;
    float get_average_rating() const;
    float get_average_age() const;
    float getMaletoFemaleRatio() const;
    void addReview(int rating, int age, int gender);
    int getReviewCount() const;
};

// Function declarations
std::vector<User> parseUserFile(const std::string& filename);
std::vector<RatingEntry> parseRatingFile(const std::string& filename);
std::vector<MovieT> parseMovieFile(const std::string& filename);
std::vector<MovieData> parseData();

#endif //DSAPROJECT3_DATAPARSING_H
