#include <iostream>
#include <numeric>
#include <utility>
#include <vector>

void printTable(const std::vector<std::vector<int>>&);
int getHigherSandWatch(const std::vector<std::vector<int>>&);

int main(int argc, char **argv) {
  std::vector<std::vector<int>> table(4, std::vector<int>(4, 0));

  for(auto& row : table)
    std::fill(row.begin(), row.end(), 1);

  table[0][1] = 3;
  table[0][2] = 2;
  table[0][3] = 3;
  table[1][2] = 2;
  table[2][1] = 2;
  table[2][2] = 2;
  table[2][3] = 3;

  std::cout << "Print Table: \n";
  printTable(table);
  std::cout << std::endl << "Relojes: " << getHigherSandWatch(table) << std::endl;

  return 0;
}

int getHigherSandWatch(const std::vector<std::vector<int>>& table) {
  int higher = 0;
  std::vector<std::pair<int, int>> sandWatch = {
    {0, 0}, {0, 1}, {0, 2}, {1, 1}, {2, 0}, {2, 1}, {2, 2}
  };

  for(int i = 0; i <= (table.size() - 3); ++i) {
    for(int j = 0; j <= (table.size() - 3); ++j) {
      int watchSandCount = std::accumulate(
        sandWatch.begin(), sandWatch.end(), 0,
        [&table, i, j](int sum, const std::pair<int, int>& offset) {
          return sum + table[i + offset.first][j + offset.second];
        }
      );

      higher = std::max(higher, watchSandCount);
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
