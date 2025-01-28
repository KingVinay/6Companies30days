#include<bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int dfs(vector<vector<int>> &dp,int dist, int steps){
    if(dist > steps || steps < 0){
        return 0;
    }

    if(steps == 0){
        return dist == 0 ? 1:0;
    }

    if(dp[dist][steps] != -1){
        return dp[dist][steps];
    }

    dp[dist][steps] = (dfs(dp,dist+1,steps-1) + dfs(dp,abs(dist-1),steps-1)) % MOD;
    return dp[dist][steps];
}

int numberOfWays(int startPos, int endPos, int k) {
    vector<vector<int>> dp(k+1,vector<int>(k+1,-1));
    return dfs(dp,abs(startPos - endPos),k);
}

int main()
{}