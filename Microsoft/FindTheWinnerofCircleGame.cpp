#include<bits/stdc++.h>
using namespace std;
// Using Josephus Formula -[ R(n,k) = (R(n-1, k) + k)% n ]
int findTheWinner(int n, int k) {
        int winner = 0;
        for(int i=2;i<=n;i++){
            winner = (winner + k)% i; 
        }

        return (winner+1);
    }

int main(){
  int n, k;
  cin >> n >> k;
  cout << findTheWinner(n, k) << endl;
  return 0;
}