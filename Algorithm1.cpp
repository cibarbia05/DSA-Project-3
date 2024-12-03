#include "Algorithm1.h"
#include <queue>
#include <vector>

using namespace std;

Movie Algorithm1::findKthRatedMovieHeap(vector<Movie>& movies, int k) {
    //max heap to store by avg rating
    priority_queue<pair<double, int>> maxHeap;

    //populate heap (rating, index) pairs
    for (int i = 0; i < movies.size(); i++) {
        maxHeap.push({movies[i].getAvgRating(), i});
    }

    //extract max k-1 times
    for (int i = 1; i < k; i++) {
        maxHeap.pop();
    }

    //top element is now kth largest
    int targetIndex = maxHeap.top().second;
    return movies[targetIndex];
}