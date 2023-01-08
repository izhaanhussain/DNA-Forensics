#include <iostream>
#include <string>
#include <vector>

#include "functions.hpp"
#include "utilities.hpp"

int main(int argc, char* argv[]) {
  if (argc != 3) {
    std::cerr << "Usage: " << argv[0] << " [input_file] [dna_sequence]"
              << std::endl;
    return 1;
  }
  std::string filename = argv[1];
  std::string sequence = argv[2];
  std::vector<std::vector<std::string>> main_vec = ReadFile(filename);

  std::cout << FindOwner(main_vec, sequence) << std::endl;
  return 0;
}