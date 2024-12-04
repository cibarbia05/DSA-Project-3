#ifndef DSAPROJECT3_USER_H
#define DSAPROJECT3_USER_H
#include <iostream>

using namespace std;

class User {
private:
    int userId;
    int age;
    int intGender;
    string gender;
    string occupation;
    string zipCode;

public:
    User(int id, int userAge, const string& userGender,
         const string& userOccupation, const string& userZipCode);
    int getUserId() const;
    int getAge() const;
    int getGender() const;
    string getOccupation() const;
    string getZipCode() const;
    void printUser() const;
};

#endif //DSAPROJECT3_USER_H