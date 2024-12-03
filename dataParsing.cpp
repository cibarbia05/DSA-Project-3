
#include "dataParsing.h"
const std::vector<std::string> GENRE_NAMES = {
        "Unknown", "Action", "Adventure", "Animation", "Children's", "Comedy",
        "Crime", "Documentary", "Drama", "Fantasy", "Film-Noir", "Horror",
        "Musical", "Mystery", "Romance", "Sci-Fi", "Thriller", "War", "Western"
};

// RatingEntry class implementation
RatingEntry::RatingEntry(int user, int item, int rate)
        : userId(user), itemId(item), rating(rate) {}

int RatingEntry::getUserId() const { return userId; }
int RatingEntry::getItemId() const { return itemId; }
int RatingEntry::getRating() const { return rating; }

void RatingEntry::printEntry() const {
    std::cout << "User ID: " << userId
              << ", Item ID: " << itemId
              << ", Rating: " << rating << std::endl;
}

// User class implementation
User::User(int id, int userAge, const std::string& userGender,
           const std::string& userOccupation, const std::string& userZipCode)
        : userId(id), age(userAge), gender(userGender),
          occupation(userOccupation), zipCode(userZipCode) {}

int User::getUserId() const { return userId; }
int User::getAge() const { return age; }
int User::getGender() const {
    if (gender == "M") {
        return 1;
    }
    return 0;
}
std::string User::getOccupation() const { return occupation; }
std::string User::getZipCode() const { return zipCode; }

void User::printUser() const {
    std::cout << "User ID: " << userId
              << ", Age: " << age
              << ", Gender: " << gender
              << ", Occupation: " << occupation
              << ", Zip Code: " << zipCode << std::endl;
}

// Movie class implementation
Movie::Movie(int id, const std::string& movieTitle, const std::string& release,
             const std::string& url, const std::vector<int>& genreFlags)
        : movieId(id), title(movieTitle), releaseDate(release), imdbUrl(url) {
    // Add genres based on genre flags
    for (size_t i = 0; i < genreFlags.size(); ++i) {
        if (genreFlags[i] == 1) {
            genres.push_back(GENRE_NAMES[i]);
        }
    }
}

int Movie::getMovieId() const { return movieId; }
std::string Movie::getTitle() const { return title; }
std::string Movie::getReleaseDate() const { return releaseDate; }
std::string Movie::getImdbUrl() const { return imdbUrl; }
std::vector<std::string> Movie::getGenres() const { return genres; }

void Movie::printMovie() const {
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

// MovieData class implementation
MovieData::MovieData() : name(""), genre({}) {}

MovieData::MovieData(std::string newName, std::vector<std::string> newGenre, std::string date)
        : name(newName), genre(newGenre), realeaseDate(date) {}

std::string MovieData::get_genre() const {
    for(auto gen : genre) {
        return gen;
    }
    return "";
}

std::string MovieData::get_realease_date() const {
    return realeaseDate;
}

std::string MovieData::get_name() const {
    return name;
}

float MovieData::get_average_rating() const {
    return review_count > 0 ? total_rating / review_count : 0.0;
}

float MovieData::get_average_age() const {
    return review_count > 0 ? total_age / review_count : 0.0;
}

float MovieData::getMaletoFemaleRatio() const {
    return review_count > 0 ? (average_gender * 100.0) : 0.0;
}

void MovieData::addReview(int rating, int age, int gender) {
    ++review_count;

    // Calculate cumulative total
    total_rating += rating;
    average_rating = total_rating / review_count;

    total_age += age;
    average_age = total_age / review_count;

    total_gender += gender;
    average_gender = total_gender / review_count;
}

int MovieData::getReviewCount() const {
    return review_count;
}

// Function implementations
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
        std::vector<Movie> movies = parseMovieFile(movieFilename);
        std::cout << "Total movies parsed: " << movies.size() << std::endl;

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

        std::vector<MovieData> returnData;
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
