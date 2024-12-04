#include <vector>
#include <iostream>
#include "Movie.h"
#include "Algorithm1.h"
#include "Algorithm2.h"
#include "InputHelpers.h"
#include "DataParsing.h"
using namespace std;

int main() {
    // // Define genres as a vector
    // vector<string> genres = {
    //     "Action", "Adventure", "Animation", "Children's", "Comedy", "Crime",
    //     "Documentary", "Drama", "Fantasy", "Film-Noir", "Horror", "Musical",
    //     "Mystery", "Romance", "Sci-Fi", "Thriller", "War", "Western"
    // };
    //
    // cout << "Welcome to the Movie Matcher System!\n\n";
    //
    // // Prompt user for inputs
    // int genreIndex = promptGenre();
    // int decade = promptDecade();
    // int age = promptAge();
    //
    // // Map the genreIndex to the genre name
    // string genre = genres[genreIndex - 1];
    //
    // // Display the collected inputs
    // cout << "\nThank you for your input!\n";
    // cout << "Preferred Genre: " << genre << "\n"
    //      << "Preferred Decade: " << decade << "\n"
    //      << "Age: " << age << "\n";

    // // Placeholder for further functionality
    // cout << "\n[Use this information to filter and recommend movies.]\n";

    // return 0;

    vector<Movie> movies = parseData();
    int k = 4;
    Movie kthLargestRatingMovie = Algorithm2::findKthHighestRatingMovie(movies, k);
    cout << kthLargestRatingMovie.getName() << " - " << kthLargestRatingMovie.getDate() << " - " << kthLargestRatingMovie.getAvgRating();

    Movie kthLargestRatingMovieHeap = Algorithm1::findKthRatedMovieHeap(movies, k);
    cout << "\n" << kthLargestRatingMovieHeap.getName() << " - " << kthLargestRatingMovieHeap.getDate() << " - " << kthLargestRatingMovieHeap.getAvgRating();

    return 0;
}
