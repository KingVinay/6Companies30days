#include<bits/stdc++.h>
using namespace std;

vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int> ans;
        int n = nums.size();

        vector<pair<int,int>> pa;
        for(int i=0;i<n;i++){
            pa.push_back({i,nums[i]});
        }

        sort(pa.begin(),pa.end(),[](auto&a,auto&b){
            return a.second > b.second;
        });

        sort(pa.begin(),pa.begin()+k,[](auto&a,auto&b){
            return a.first < b.first;
        });

        for(int i=0;i<k;i++){
            ans.push_back(pa[i].second);
        }
        
        return ans;
    }

int main()
{
  vector<int> nums = {1,2,3,4,5};
  int k = 3;
  vector<int> ans = maxSubsequence(nums, k);
  for(int i=0;i<ans.size();i++){
    cout << ans[i] << " ";
  }
  cout << endl;
  return 0;
}