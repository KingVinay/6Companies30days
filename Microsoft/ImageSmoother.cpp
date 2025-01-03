#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<vector<int>> grid(n, vector<int>(n));

  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      cin >> grid[i][j];
    }
  }
  vector<vector<int>> result = imageSmoother(grid);

  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      cout << result[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}

vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size();
        int n = img[0].size();
        vector<vector<int>> ans(m, vector<int>(n));

        vector<pair<int, int>> directions = {{-1, -1}, {-1, 0}, {-1, 1},
                                             {0, -1},  {0, 0},  {0, 1},
                                             {1, -1},  {1, 0},  {1, 1}};

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int sum = 0;
                int count = 0;
                for(auto dir: directions){
                    int x = i + dir.first;
                    int y = j + dir.second;

                    if(x>=0 && x<m && y>=0 && y<n){
                        sum += img[x][y];
                        count++;
                    }
                }

                ans[i][j] = floor(sum/count);
            }
        }

        return ans;
    }vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size();
        int n = img[0].size();
        vector<vector<int>> ans(m, vector<int>(n));

        vector<pair<int, int>> directions = {{-1, -1}, {-1, 0}, {-1, 1},
                                             {0, -1},  {0, 0},  {0, 1},
                                             {1, -1},  {1, 0},  {1, 1}};

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int sum = 0;
                int count = 0;
                for(auto dir: directions){
                    int x = i + dir.first;
                    int y = j + dir.second;

                    if(x>=0 && x<m && y>=0 && y<n){
                        sum += img[x][y];
                        count++;
                    }
                }

                ans[i][j] = floor(sum/count);
            }
        }

        return ans;
    }