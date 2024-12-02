#ifndef ALGORITHM2_H
#define ALGORITHM2_H

#include <vector>
#include "Movie.h"

class Algorithm2 {
private:
    static Movie quickSelect(vector<Movie> &movies, int low, int high, int target);
    static int partition(vector<Movie>& movies, int low, int high);
public:
    static Movie findKthHighestRatingMovie(vector<Movie>& movies, int k);
};

#endif