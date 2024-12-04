
#ifndef DSAPROJECT3_USERINPUT_H
#define DSAPROJECT3_USERINPUT_H

#include <iostream>
#include <string>
#include <limits>
#include <algorithm>


#include <iostream>
#include <string>
#include <limits>
#include <algorithm>

// Function prototypes
std::string toLowercase(std::string str);
bool validateYesNo(const std::string& input);
bool validateAge(int age);
int getAgeInput();
bool validateNum(int num);
int getNumInput();
std::string getYesNoInput();
void displayWelcomeArt();

int userInput();

#endif