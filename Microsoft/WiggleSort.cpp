#include<bits/stdc++.h>
using namespace std;

void wiggleSort(vector<int>& nums) {
        vector <int> x(nums);
      sort(x.begin(), x.end());
      int i = x.size() - 1 ;
      int j = (x.size() - 1)/2;
      int n = nums.size();
      for(int l = 0; l < n; l +=2){
         nums[l] = x[j--];
      }
      for(int l = 1; l < n; l +=2){
         nums[l] = x[i--];
      }
   }
int main()
{
  vector<int> nums = {1, 5, 1, 1, 6, 4};
  wiggleSort(nums);
  for(int i=0;i<nums.size();i++){
      cout<<nums[i]<<" ";
  }
  return 0;
}