#include<bits/stdc++.h>
using namespace std;

int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]] = i;
        }

        set<pair<int,int>> st;

        for(int i=0;i<nums.size();i++){
            int x = nums[i] - k;
            if(mp.find(x)!=mp.end() && mp[x]!=i){
                st.insert({x,nums[i]});
            }
        }

        return st.size();
    }

int main()
{
  vector<int> nums = {1, 3, 1, 5, 4};
  int k = 2;
  cout << findPairs(nums, k) << endl;
  return 0;
}