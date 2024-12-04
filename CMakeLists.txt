cmake_minimum_required(VERSION 3.27)
project(DSAProject3)

set(CMAKE_CXX_STANDARD 17)

add_executable(DSAProject3 main.cpp
        Algorithms/Algorithm1.cpp
        Algorithms/Algorithm1.h
        Model/Movie.cpp
        Model/Movie.h
        Model/Movie.h
        Algorithms/Algorithm2.cpp
        Algorithms/Algorithm2.h
        DataHandling/DataParsing.cpp
        Model/MovieT.cpp
        Model/RatingEntry.cpp
        Model/User.cpp
        DataHandling/UserInput.cpp)