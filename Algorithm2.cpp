#include "Algorithm2.h"
#include "algorithm"

using namespace std;

Movie Algorithm2::findKthHighestRatingMovie(vector<Movie>& movies, int k) {
    return quickSelect(movies, 0, movies.size() - 1, movies.size() - k);
}

Movie Algorithm2::quickSelect(vector<Movie>& movies, int low, int high, int targetInd) {
     if (low < high)
     {
         int pivotInd = partition(movies, low, high);
         if (pivotInd == targetInd)
             return movies[pivotInd];
         else if (pivotInd > targetInd)
             quickSelect(movies, low, pivotInd - 1, targetInd);
         else
             quickSelect(movies, pivotInd + 1, high, targetInd);
     }
}

int Algorithm2::partition(vector<Movie>& movies, int low, int high) {
    double pivot = movies[low].getAvgRating();
    int l = low;
    int h = high;
    while (l < h) {
        while (l <= high && movies[l].getAvgRating() <= pivot) {
            l++;
        }
        while (h >= low && movies[h].getAvgRating() > pivot) {
            h--;
        }
        if (l < h)
        {
            swap(movies[l], movies[h]);
        }
    }
    swap(movies[low], movies[h]);
    return h;
}