#ifndef DSAPROJECT3_RATINGENTRY_H
#define DSAPROJECT3_RATINGENTRY_H


class RatingEntry {
private:
    int userId;
    int itemId;
    int rating;

public:
    RatingEntry(int user, int item, int rate);
    int getUserId() const;
    int getItemId() const;
    int getRating() const;
    void printEntry() const;
};


#endif //DSAPROJECT3_RATINGENTRY_H
