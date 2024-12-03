#include <iostream>
#include "RatingEntry.h"

using namespace std;
RatingEntry::RatingEntry(int user, int item, int rate)
        : userId(user), itemId(item), rating(rate) {}

int RatingEntry::getUserId() const { return userId; }
int RatingEntry::getItemId() const { return itemId; }
int RatingEntry::getRating() const { return rating; }

void RatingEntry::printEntry() const {
    cout << "User ID: " << userId
              << ", Item ID: " << itemId
              << ", Rating: " << rating << std::endl;
}