#include <vector>
#include <iostream>
#include "Movie.h"
#include "Algorithm1.h"
#include "Algorithm2.h"
#include "input_helpers.h"
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

    string m1Title = "Movie1";
    string m1Date = "date1";
    Movie m1(m1Title, m1Date, 4.94);
    Movie m2(m1Title, m1Date, 2.12);
    Movie m3(m1Title, m1Date, 5.00);
    Movie m4(m1Title, m1Date, 4.01);
    Movie m5(m1Title, m1Date, 1.76);
    Movie m6(m1Title, m1Date, 0.37);
    Movie m7(m1Title, m1Date, 3.80);

    vector<Movie> movies{ m1, m2, m3, m4, m5, m6, m7 };

    int k = 2;
    Movie kthLargestRatingMovie = Algorithm2::findKthHighestRatingMovie(movies, k);
    cout << kthLargestRatingMovie.getTitle() << " - " << kthLargestRatingMovie.getDate() << " - " << kthLargestRatingMovie.getAvgRating();

    Movie kthLargestRatingMovieHeap = Algorithm1::findKthRatedMovieHeap(movies, k);
    cout << "\n" << kthLargestRatingMovieHeap.getTitle() << " - " << kthLargestRatingMovieHeap.getDate() << " - " << kthLargestRatingMovieHeap.getAvgRating();

    return 0;
}
