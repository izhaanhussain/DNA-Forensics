#include "functions.hpp"

#include "utilities.hpp"

// Checks who the sequence belongs to
std::string FindOwner(const std::vector<std::vector<std::string>>& main_vec,
                      const std::string& sequence) {
  std::vector<std::vector<int>> int_vec = ConvertStrings(main_vec);
  std::vector<std::vector<std::string>> entire_vec =
      EntireConsecsVector(main_vec, int_vec);
  std::string owner;
  int num_owners = 0;
  for (unsigned int i = 0; i < entire_vec.size(); ++i) {
    if (CheckConsecs(sequence, entire_vec.at(i))) {
      num_owners++;
      owner = entire_vec.at(i).at(0);
    }
  }
  if (num_owners == 1) {
    return owner;
  }
  return "No match";
}

// Checks if a line has all instances of consecutive STR
bool CheckConsecs(std::string checker, std::vector<std::string> consecs) {
  bool ret = true;

  for (unsigned int i = 1; i < consecs.size(); ++i) {
    if (checker.find(consecs.at(i)) != std::string::npos) {
      checker.erase(checker.find(consecs.at(i)), consecs.at(i).length());
    } else {
      ret = false;
    }
  }
  return ret;
}

// Reads in a file and creates a vector with all the info
std::vector<std::vector<std::string>> ReadFile(const std::string& file_name) {
  std::vector<std::vector<std::string>> ret;
  std::vector<std::string> temp;

  std::ifstream ifs{file_name};
  for (std::string line; std::getline(ifs, line); line = "") {
    temp = utilities::GetSubstrs(line, ',');
    ret.push_back(temp);
  }
  return ret;
}

// Converts the string numbers in the main vector into ints
std::vector<std::vector<int>> ConvertStrings(
    const std::vector<std::vector<std::string>>& input) {
  std::vector<std::vector<int>> ret;
  std::vector<int> temp;

  for (unsigned int i = 1; i < input.size(); ++i) {
    for (unsigned int j = 1; j < input.at(i).size(); ++j) {
      temp.push_back(std::stoi(input.at(i).at(j)));
    }
    ret.push_back(temp);
    temp.clear();
  }
  return ret;
}

// Builds a vector of consecs for all the people
std::vector<std::vector<std::string>> EntireConsecsVector(
    std::vector<std::vector<std::string>> mainVec,
    std::vector<std::vector<int>> intVec) {
  std::vector<std::vector<std::string>> ret;
  std::vector<std::string> temp;

  for (unsigned int i = 1; i < mainVec.size(); ++i) {
    ret.push_back({mainVec.at(i).at(0)});
  }

  for (unsigned int i = 0; i < intVec.size(); ++i) {
    temp = BuildConsecsVector(mainVec.at(0), intVec.at(i));
    for (unsigned int j = 0; j < temp.size(); ++j) {
      ret.at(i).push_back(temp.at(j));
    }
  }
  return ret;
}

// Builds a vector of consecs
std::vector<std::string> BuildConsecsVector(std::vector<std::string> strs,
                                            std::vector<int> frequencies) {
  std::vector<std::string> ret;
  std::string temp;

  for (unsigned int i = 0; i < frequencies.size(); ++i) {
    temp = ConsecSTR(strs.at(i + 1), frequencies.at(i));
    ret.push_back(temp);
  }
  return ret;
}

// Builds a consecutive STR
std::string ConsecSTR(std::string str, unsigned int size) {
  std::string ret;

  for (unsigned int i = 0; i < size; ++i) {
    for (unsigned int j = 0; j < str.length(); ++j) {
      ret.push_back(str.at(j));
    }
  }
  return ret;
}