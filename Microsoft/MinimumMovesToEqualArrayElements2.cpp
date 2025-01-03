#include<bits/stdc++.h>
using namespace std;

int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int mid = nums.size()/2;
        int res = 0;
        for(int i=0;i<nums.size();i++){
            res += abs(nums[i] - nums[mid]);
        }

        return res;
    }

int main()
{
  vector<int> nums = {1,2,3};
  cout << minMoves2(nums) << endl;
  return 0;
}