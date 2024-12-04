#ifndef ALGORITHM1_H
#define ALGORITHM1_H
#include <vector>
#include "Movie.h"

using namespace std;

class Algorithm1 {
public:
    static Movie findKthRatedMovieHeap(vector<Movie>& movies, int k);
    static Movie findKthRatedGenre(vector<Movie> movies, int k, vector<string> genres);
};

#endif