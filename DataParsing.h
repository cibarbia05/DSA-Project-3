#ifndef DSAPROJECT3_DATAPARSING_H
#define DSAPROJECT3_DATAPARSING_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include "Movie.h"
#include "RatingEntry.h"
#include "User.h"
#include "MovieT.h"

std::vector<User> parseUserFile(const std::string& filename);
std::vector<RatingEntry> parseRatingFile(const std::string& filename);
std::vector<MovieT> parseMovieFile(const std::string& filename);
std::vector<Movie> parseData();

#endif //DSAPROJECT3_DATAPARSING_H