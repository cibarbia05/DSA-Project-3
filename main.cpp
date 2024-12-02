#include <iostream>
#include <vector>
#include "Movie.h"
#include "Algorithm2.h"
using namespace std;

int main() {
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

    return 0;
}
