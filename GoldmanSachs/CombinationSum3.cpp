#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        dfs(k, n, 1, {}, ans);
        return ans;
    }

    void dfs(int k, int n, int s, vector<int>&& path, vector<vector<int>>& ans) {
        if (k == 0 && n == 0) {
            ans.push_back(path);
            return;
        }
        if (k == 0 || n <= 0)
            return;

        for (int i = s; i <= 9; ++i) {
            path.push_back(i);
            dfs(k - 1, n - i, i + 1, move(path), ans);
            path.pop_back();
        }
    }

int main()
{
  int k = 3, n = 7;
  vector<vector<int>> result = combinationSum3(k, n);
  for (auto v : result) {
    for (int i : v) {
      cout << i << " ";
    }
    cout << endl;
  }
  return 0;
}