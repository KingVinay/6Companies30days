#include<bits/stdc++.h>
using namespace std;

int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        unordered_map<string,int> memo;
        return dfs(price,special,needs,memo);
    }

    string getKey(vector<int>&needs){
        string key="";
        for(int need:needs){
            key += to_string(need) + ",";
        }
        return key;
    }

    int dfs(vector<int>& price, vector<vector<int>>& special, vector<int>& needs, unordered_map<string,int>&memo){
        string key = getKey(needs);
        if(memo.find(key)!=memo.end()){
            return memo[key];
        }

        bool EmptyNeed = true;
        for(int need: needs){
            if(need > 0){
                EmptyNeed = false;
                break;
            }
        }
        if(EmptyNeed){
            return 0;
        }

        int minCost = 0;
        for(int i=0;i<price.size();i++){
            minCost += price[i]*needs[i];
        }

        for(auto offer: special){
            vector<int> newNeeds = needs;
            bool valid = true;

            for(int i=0;i<needs.size();i++){
                if(offer[i] > newNeeds[i]){
                    valid = false;
                    break;
                }
                newNeeds[i]-= offer[i];
            }

            if(valid){
                minCost = min(minCost, offer[needs.size()] + dfs(price,special,newNeeds,memo));
            }
        }
        memo[key] = minCost;
        return minCost;
    }

int main()
{
  vector<int> price = {2,5};
  vector<vector<int>> special = {{3,0,5},{1,2,10}};
  vector<int> needs = {3,2};
  cout << shoppingOffers(price, special, needs) << endl;
  return 0;
}