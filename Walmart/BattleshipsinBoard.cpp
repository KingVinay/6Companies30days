#include<bits/stdc++.h>
using namespace std;

int countBattleships(vector<vector<char>>& board) {
        int ans = 0;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j] == 'X'){
                    if((i==0 || board[i-1][j] == '.') && (j==0 || board[i][j-1] == '.')){
                        ans++;
                    }
                }
            }

        }
        return ans;
}
int main()
{
   vector<vector<char>> board = {{'X','.','.','X'},{'X','.','.','X'},{'X','.','.','X'}};
   cout << countBattleships(board) << endl;
   return 0;
}