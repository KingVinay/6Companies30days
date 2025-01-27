#include<bits/stdc++.h>
using namespace std;

int minDays(vector<vector<int>>& grid) {
    if (disconnected(grid))
      return 0;

    for (int i = 0; i < grid.size(); ++i)
      for (int j = 0; j < grid[0].size(); ++j)
        if (grid[i][j] == 1) {
          grid[i][j] = 0;
          if (disconnected(grid))
            return 1;
          grid[i][j] = 1;
        }

    return 2;
  }

  static constexpr int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

  bool disconnected(const vector<vector<int>>& grid) {
    int islandsCount = 0;
    vector<vector<bool>> seen(grid.size(), vector<bool>(grid[0].size()));
    for (int i = 0; i < grid.size(); ++i)
      for (int j = 0; j < grid[0].size(); ++j) {
        if (grid[i][j] == 0 || seen[i][j])
          continue;
        if (++islandsCount > 1)
          return true;
        dfs(grid, i, j, seen);
      }
    return islandsCount != 1;
  }

  void dfs(const vector<vector<int>>& grid, int i, int j,
           vector<vector<bool>>& seen) {
    seen[i][j] = true;
    for (const auto& [dx, dy] : dirs) {
      const int x = i + dx;
      const int y = j + dy;
      if (x < 0 || x == grid.size() || y < 0 || y == grid[0].size())
        continue;
      if (grid[x][y] == 0 || seen[x][y])
        continue;
      dfs(grid, x, y, seen);
    }
  }

int main()
{
  vector<vector<int>> grid = {{1,1,0,0},{1,1,0,0},{0,0,0,1},{0,0,0,1}};
  cout << minDays(grid) << endl;
  return 0;
}