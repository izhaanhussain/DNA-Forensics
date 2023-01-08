#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "utilities.hpp"

// Checks who the sequence belongs to
std::string FindOwner(const std::vector<std::vector<std::string>>& main_vec,
                      const std::string& sequence);

// Reads in a file and creates a vector with all the info
std::vector<std::vector<std::string>> ReadFile(const std::string& file_name);

// Converts the string numbers in the main vector into ints
std::vector<std::vector<int>> ConvertStrings(
    const std::vector<std::vector<std::string>>& input);

// Builds a vector of consecs for all the people
std::vector<std::vector<std::string>> EntireConsecsVector(
    std::vector<std::vector<std::string>> mainVec,
    std::vector<std::vector<int>> intVec);

// Builds a vector of consecs
std::vector<std::string> BuildConsecsVector(std::vector<std::string> strs,
                                            std::vector<int> frequencies);

// Builds a consecutive STR
std::string ConsecSTR(std::string str, unsigned int size);

// Checks if a line has all instances of consecutive STR
bool CheckConsecs(std::string checker, std::vector<std::string> consecs);

#endif