#include<bits/stdc++.h>
using namespace std;

bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    for(int k=0;k<9;k++){
                        if(k!=i && board[i][j]==board[k][j]){
                            return false;
                        }
                     }
                     for(int k=0;k<9;k++){
                         if(k!=j && board[i][j]==board[i][k]){
                             return false;
                         }
                     }
                     
                     int boxr = (i/3)*3, boxc = (j/3)*3;
                     for(int m=0;m<3;m++){
                         for(int n=0;n<3;n++){
                             if(m+boxr!=i && n+boxc!=j && board[m+boxr][n+boxc]==board[i][j]){
                                 return false;
                             }
                         }
                     }
                }
            }
        }
        return true;
}

int main()
{
  vector<vector<char>> board = {{'5','3','.','.','7','.','.','.','.'},
                                {'6','.','.','1','9','5','.','.','.'},
                                {'.','9','8','.','.','.','6','.','.'},
                                {'8','.','.','.','6','.','.','.','3'},
                                {'4','.','.','8','.','3','.','.','1'},
                                {'7','.','.','.','2','.','.','.','6'},
                                {'.','6','.','.','.','.','2','8','.'},
                                {'.','.','.','4','1','9','.','.','5'},
                                {'.','.','.','.','8','.','.','7','9'}};
  cout << isValidSudoku(board) << endl;
  return 0;
}