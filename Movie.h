#include <string>

using namespace std;

class Movie {
private:
    string title;
    string date;
    float avgRating;
public:
    Movie();
    Movie(string& t, string& d, float& a);
    string const& getTitle() const;
    string const& getDate() const;
    float const& getAvgRating() const;
};
