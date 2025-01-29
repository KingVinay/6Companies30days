#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
    int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int m = isWater.size();
    int n = isWater[0].size();
    
    vector<vector<int>> ans(m, vector<int>(n, -1));
    queue<pair<int, int>> q;

    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            if (isWater[i][j] == 1) {
                q.emplace(i, j);
                ans[i][j] = 0;
            }

    while (!q.empty()) {
        const auto [i, j] = q.front();
        q.pop();
        for (const auto& [dx, dy] : dirs) {
            const int x = i + dx;
            const int y = j + dy;
            if (x < 0 || x == m || y < 0 || y == n)
                continue;
            if (ans[x][y] != -1)
                continue;
            ans[x][y] = ans[i][j] + 1;
            q.emplace(x, y);
        }
    }

    return ans;
}

int main()
{
    vector<vector<int>> isWater = {{0,0,1},{1,0,0},{0,0,0}};
    vector<vector<int>> result = highestPeak(isWater);
    for(auto row : result) {
        for(auto cell : row) {
          cout << cell << " ";
        }
        cout << endl;
    }
    return 0;
}