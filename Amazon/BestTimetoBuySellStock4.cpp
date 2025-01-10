#include<bits/stdc++.h>
using namespace std;

int maxProfitAtK(int i, int k, bool buy, vector<vector<vector<int>>>& memo,vector<int>& prices){
        if(k<=0 || i>=prices.size()){
            return 0;
        }

        if(memo[i][k][buy]!= -1){
            return memo[i][k][buy];
        }

        int res = 0, profit = 0;

        if(buy){
            profit = maxProfitAtK(i+1,k,0,memo,prices) - prices[i];
            res = max(res, profit);
        }else{
            profit = maxProfitAtK(i+1,k-1,1,memo,prices) + prices[i];
            res = max(res, profit);
        }
        profit = maxProfitAtK(i+1,k,buy,memo,prices);
        res = max(res,profit);
        memo[i][k][buy] = res;

        return res;
    }

    int maxProfit(int k, vector<int>& prices) {
        vector<vector<vector<int>>> memo(prices.size()+1,vector<vector<int>>(k+1,vector<int>(2,-1)));
        return maxProfitAtK(0,k,1,memo,prices);
    }

int main()
{
  vector<int> prices = {3,3,5,0,0,3,1,4};
  int k = 2;
  cout << maxProfit(k, prices) << endl;
  return 0;
}

