#include "DataParsing.h"
#include "Movie.h"

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

std::vector<MovieT> parseMovieFile(const std::string& filename) {
    std::vector<MovieT> movies;
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

std::vector<Movie> parseData() {
    try {
        //reviews
        std::string dataFilename = "u.data";
        std::vector<RatingEntry> movieRatings = parseRatingFile(dataFilename);
        std::cout << "Total ratings parsed: " << movieRatings.size() << std::endl;

        //users
        std::string userFilename = "u.user";
        std::vector<User> users = parseUserFile(userFilename);
        std::cout << "Total users parsed: " << users.size() << std::endl;

        //movies
        std::string movieFilename = "u.item";
        std::vector<MovieT> movies = parseMovieFile(movieFilename);
        std::cout << "Total movies parsed: " << movies.size() << std::endl;

        //We must now combine this data
        std::map<std::string, Movie> Data;
        for (auto rating : movieRatings) {
            std::string movieName = movies[rating.getItemId() - 1].getTitle();
            std::string date = movies[rating.getItemId() - 1].getReleaseDate();
            int entryRating = rating.getRating();
            int age = users[rating.getUserId() - 1].getAge();
            int gender = users[rating.getUserId() -1 ].getGender();
            std::vector<std::string> genereST = movies[rating.getItemId() - 1].getGenres();
            if (Data.find(movieName) == Data.end()) {
                Data[movieName] = Movie(movieName, genereST, date);
            }
            Data[movieName].addReview(entryRating, age, gender);
        }
        std::vector<Movie> returnData;
        for(auto mov : Data) {
            returnData.push_back(mov.second);
        }
        return returnData;
    }
    catch (const std::exception& e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
        return {};
    }
}