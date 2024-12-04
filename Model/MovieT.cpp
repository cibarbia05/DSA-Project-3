#include "MovieT.h"

const std::vector<std::string> GENRE_NAMES = {
        "Unknown", "Action", "Adventure", "Animation", "Children's", "Comedy",
        "Crime", "Documentary", "Drama", "Fantasy", "Film-Noir", "Horror",
        "Musical", "Mystery", "Romance", "Sci-Fi", "Thriller", "War", "Western"
};

MovieT::MovieT(int id, const std::string& movieTitle, const std::string& release,
               const std::string& url, const std::vector<int>& genreFlags)
        : movieId(id), title(movieTitle), releaseDate(release), imdbUrl(url) {
    // Add genres based on genre flags
    for (size_t i = 0; i < genreFlags.size(); ++i) {
        if (genreFlags[i] == 1) {
            genres.push_back(GENRE_NAMES[i]);
        }
    }
}

int MovieT::getMovieId() const { return movieId; }

std::string MovieT::getTitle() const { return title; }

std::string MovieT::getReleaseDate() const { return releaseDate; }

std::string MovieT::getImdbUrl() const { return imdbUrl; }

std::vector<std::string> MovieT::getGenres() const { return genres; }

void MovieT::printMovie() const {
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