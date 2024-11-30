#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <map>
#include <queue>


const std::vector<std::string> GENRE_NAMES = {
    "Unknown", "Action", "Adventure", "Animation", "Children's", "Comedy",
    "Crime", "Documentary", "Drama", "Fantasy", "Film-Noir", "Horror",
    "Musical", "Mystery", "Romance", "Sci-Fi", "Thriller", "War", "Western"
};
// Custom class to hold rating information
class RatingEntry {
private:
    int userId;
    int itemId;
    int rating;

public:
    // Constructor
    RatingEntry(int user, int item, int rate)
        : userId(user), itemId(item), rating(rate) {}

    // Getter methods
    int getUserId() const { return userId; }
    int getItemId() const { return itemId; }
    int getRating() const { return rating; }

    // Optional: Print method for debugging
    void printEntry() const {
        std::cout << "User ID: " << userId
                  << ", Item ID: " << itemId
                  << ", Rating: " << rating << std::endl;
    }
};
class User {
private:
    int userId;
    int age;
    int intGender;
    std::string gender;
    std::string occupation;
    std::string zipCode;

public:
    // Constructor
    User(int id, int userAge, const std::string& userGender,
         const std::string& userOccupation, const std::string& userZipCode)
        : userId(id), age(userAge), gender(userGender),
          occupation(userOccupation), zipCode(userZipCode) {}

    // Getter methods
    int getUserId() const { return userId; }
    int getAge() const { return age; }
    int getGender() const {
        if (gender == "M") {
            return 1;
        }
        return 0;
    }
    std::string getOccupation() const { return occupation; }
    std::string getZipCode() const { return zipCode; }

    // Optional: Print method for debugging
    void printUser() const {
        std::cout << "User ID: " << userId
                  << ", Age: " << age
                  << ", Gender: " << gender
                  << ", Occupation: " << occupation
                  << ", Zip Code: " << zipCode << std::endl;
    }
};
class Movie {
private:
    int movieId;
    std::string title;
    std::string releaseDate;
    std::string imdbUrl;
    std::vector<std::string> genres;

public:
    // Constructor
    Movie(int id, const std::string& movieTitle, const std::string& release,
          const std::string& url, const std::vector<int>& genreFlags)
        : movieId(id), title(movieTitle), releaseDate(release), imdbUrl(url) {

        // Add genres based on genre flags
        for (size_t i = 0; i < genreFlags.size(); ++i) {
            if (genreFlags[i] == 1) {
                genres.push_back(GENRE_NAMES[i]);
            }
        }
    }

    // Getter methods
    int getMovieId() const { return movieId; }
    std::string getTitle() const { return title; }
    std::string getReleaseDate() const { return releaseDate; }
    std::string getImdbUrl() const { return imdbUrl; }
    std::vector<std::string> getGenres() const { return genres; }

    // Optional: Print method for debugging
    void printMovie() const {
        std::cout << "Movie ID: " << movieId
                  << ", Title: " << title
                  << ", Release Date: " << releaseDate
                  << ", IMDb URL: " << imdbUrl
                  << std::endl;

        // Print genres
        std::cout << "Genres: ";
        for (const auto& genre : genres) {
            std::cout << genre << " ";
        }
        std::cout << std::endl;
    }
};
class MovieData {
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
    //more attributes as needed
public:

    MovieData() : name(""), genre({}) {}
    MovieData(std::string newName, std::vector<std::string> newGenre, std::string date) :
        name(newName), genre(newGenre), realeaseDate(date) {}

    //returns only the first genre in the movies information
    std::string get_genre() const {
        for(auto gen : genre) {
            return gen;
        }
    }
    std::string get_realease_date() const {
        return realeaseDate;
    }
    std::string get_name() const {
        return name;
    }
    float get_average_rating() const {
        return review_count > 0 ? total_rating / review_count : 0.0;
    }
    float get_average_age() const {
        return review_count > 0 ? total_age / review_count : 0.0;
    }
    float getMaletoFemaleRatio() const {
        return review_count > 0 ? (average_gender * 100.0) : 0.0;
    }
    void addReview(int rating, int age, int gender) {
        ++review_count;

        // Calculate cumulative total
        total_rating += rating;
        average_rating = total_rating / review_count;

        total_age += age;
        average_age = total_age / review_count;

        total_gender += gender;
        average_gender = total_gender / review_count;
    }
    int getReviewCount() const {
        return review_count;
    }
};

// Function to parse the user file
std::vector<User> parseUserFile(const std::string& filename) {
    std::vector<User> users;
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return users;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string userId, age, gender, occupation, zipCode;

        // Using getline with '|' as delimiter to handle parsing
        if (std::getline(iss, userId, '|') &&
            std::getline(iss, age, '|') &&
            std::getline(iss, gender, '|') &&
            std::getline(iss, occupation, '|') &&
            std::getline(iss, zipCode)) {

            // Convert string to integer for userId and age
            users.emplace_back(
                std::stoi(userId),
                std::stoi(age),
                gender,
                occupation,
                zipCode
            );
            }
    }

    file.close();
    return users;
}

// Function to parse the data file
std::vector<RatingEntry> parseRatingFile(const std::string& filename) {
    std::vector<RatingEntry> ratings;
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return ratings;
    }
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        int userId, itemId, rating, timestamp;

        // Parse each line, discarding timestamp
        if (iss >> userId >> itemId >> rating >> timestamp) {
            ratings.emplace_back(userId, itemId, rating);
        }
    }

    file.close();
    return ratings;
}

// Function to parse the movie file
std::vector<Movie> parseMovieFile(const std::string& filename) {
    std::vector<Movie> movies;
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return movies;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string token;
        std::vector<std::string> tokens;

        // Split the line by '|'
        while (std::getline(iss, token, '|')) {
            tokens.push_back(token);
        }

        // Ensure we have enough tokens
        if (tokens.size() < 24) {
            std::cerr << "Skipping invalid line: insufficient tokens" << std::endl;
            continue;
        }

        // Convert movie ID to integer
        int movieId = std::stoi(tokens[0]);

        // Extract genre flags
        std::vector<int> genreFlags;
        for (size_t i = 5; i < tokens.size(); ++i) {
            genreFlags.push_back(std::stoi(tokens[i]));
        }

        // Create and store the Movie object
        movies.emplace_back(
            movieId,
            tokens[1],    // title
            tokens[2],    // release date
            tokens[4],    // IMDb URL
            genreFlags
        );
    }

    file.close();
    return movies;
}

std::vector<MovieData> parseData() {
    try{
        //reviews
        std::string dataFilename = "u.data";
        std::vector<RatingEntry> movieRatings = parseRatingFile(dataFilename);
        std::cout << "Total ratings parsed: " << movieRatings.size() << std::endl;         // Print out the number of ratings parsed
        //users
        std::string userFilename = "u.user";
        std::vector<User> users = parseUserFile(userFilename);
        std::cout << "Total users parsed: " << users.size() << std::endl;         // Print out the number of users parsed
        //movies
        std::string movieFilename = "u.item";
        std::vector<Movie> movies = parseMovieFile(movieFilename);
        std::cout << "Total movies parsed: " << movies.size() << std::endl;         // Print out the number of movies parsed

        //We must now combine this data
        std::map<std::string, MovieData> Data;
        for (auto rating : movieRatings) {
            std::string movieName = movies[rating.getItemId() - 1].getTitle();
            std::string date = movies[rating.getItemId() - 1].getReleaseDate();
            int entryRating = rating.getRating();
            int age = users[rating.getUserId() - 1].getAge();
            int gender = users[rating.getUserId() -1 ].getGender();
            std::vector<std::string> genereST = movies[rating.getItemId() - 1].getGenres();
            if (Data.find(movieName) == Data.end()) {
                Data[movieName] = MovieData(movieName, genereST, date);
            }
            Data[movieName].addReview(entryRating, age, gender);
        }
        /*
        for(auto mov : Data) {
            std::cout << "Title: " << mov.second.get_name() << "\n" <<
                "    Date: " << mov.second.get_realease_date() << "\n" <<
                    "        Average Rating: " << mov.second.get_average_rating() << std::endl;
        }
        */
        std::vector<MovieData> returnData;
        for(auto mov : Data) {
            returnData.push_back(mov.second);
        }
        return returnData;
    }
    catch (const std::exception& e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
    }
}

int main() {
    parseData();
    return 0;
}