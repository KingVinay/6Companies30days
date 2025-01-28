#include<bits/stdc++.h>
using namespace std;

int countDistinct(vector<int>& nums, int k, int p) {
  unordered_set<string> st;
  int count;
  for(int i=0;i<nums.size();i++){
      count = 0;
      string subarray;
      for(int j=i;j<nums.size();j++){
          if(nums[j]%p == 0 && ++count > k){
              break;
          }

          subarray += to_string(nums[j]) + ",";
          st.insert(subarray);
      }
  }

  return st.size();
}

int main()
{
  vector<int> nums = {1,2,3,4,5};
  int k = 1, p = 2;
  cout << countDistinct(nums, k, p) << endl;
  return 0;
}