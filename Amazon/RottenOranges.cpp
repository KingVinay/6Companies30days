#include<bits/stdc++.h>
using namespace std;

int orangesRotting(vector<vector<int>>& grid) {

        queue<pair<int,pair<int,int>>> pq;
        int m = grid.size(),n = grid[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if(grid[i][j]==2){
                    pq.push({0,{i,j}});
                }
            }
        }

        int ans = 0;

        while(!pq.empty()){
            pair<int,pair<int,int>> p = pq.front();
            pq.pop();
            ans = p.first;
            int i = p.second.first;
            int j = p.second.second;

            if(i>0){
                if(grid[i-1][j] == 1){
                    pq.push({ans+1,{i-1,j}});
                    grid[i-1][j] = 2;
                }
            }

            if(j>0){
                if(grid[i][j-1] == 1){
                    pq.push({ans+1,{i,j-1}});
                    grid[i][j-1] = 2;
                }
            }

            if(i < m-1){
                if(grid[i+1][j] == 1){
                    pq.push({ans+1,{i+1,j}});
                    grid[i+1][j] = 2;
                }
            }

            if(j < n-1){
                if(grid[i][j+1] == 1){
                    pq.push({ans+1,{i,j+1}});
                    grid[i][j+1] = 2;
                }
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }

        return ans;
    }

int main()
{
   vector<vector<int>> grid = {{2,1,1},{1,1,0},{0,1,1}};
   cout << orangesRotting(grid) << endl;
   return 0;
}