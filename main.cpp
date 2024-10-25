#include <iostream>
#include <vector>

void printTable(const std::vector<std::vector<int>>&);
int getHigherSandWatch(const std::vector<std::vector<int>>&);

int main(int argc, char **argv) {
  std::vector<std::vector<int>> table(4, std::vector<int>(4, 0));

  for(auto& row : table) {
    std::fill(row.begin(), row.end(), 1);
  }

  table[0][1] = 2;
  table[0][2] = 2;
  table[0][3] = 3;
  table[1][2] = 2;
  table[2][1] = 2;
  table[2][2] = 2;
  table[2][3] = 2;

  std::cout << "Print Table: \n";
  printTable(table);
  std::cout << std::endl << "Relojes: " << getHigherSandWatch(table) << std::endl;

  return 0;
}

int getHigherSandWatch(const std::vector<std::vector<int>>& table) {
  int watchSandCount = 0;
  int higher = 0;

  for(int i = 0; i < table.size(); ++i) {
    for(int j = 0; j < table.size(); ++j) {
      for(int k = j; (j + 3) <= table.size() && k < (j + 3); ++k) {
        for(int l = i; (i + 3) <= table.size() && l < (i + 3); ++l)
          if(!(k == j + 1 && (l == i || l == (i + 2))))
            watchSandCount += table[k][l];
      }

      if(watchSandCount > higher)
        higher = watchSandCount;

      watchSandCount = 0;
    }
  }

  return higher;
}

void printTable(const std::vector<std::vector<int>>& table) {
  for(const auto& row : table) {
    for(const auto& val : row)
      std::cout << val << ", ";

    std::cout << std::endl;
  }
}
