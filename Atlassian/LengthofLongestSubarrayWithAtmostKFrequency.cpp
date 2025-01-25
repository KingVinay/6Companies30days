#include<bits/stdc++.h>
using namespace std;

int maxSubarrayLength(vector<int>& nums, int k) {
        int ans = 0;
        unordered_map<int, int> count;

        for (int l = 0, r = 0; r < nums.size(); ++r) {
            ++count[nums[r]];
            while (count[nums[r]] == k + 1)
                --count[nums[l++]];
            ans = max(ans, r - l + 1);
        }

        return ans;
    }

int main()
{
  vector<int> nums = {1,2,1,2,3};
  int k = 2;
  cout << maxSubarrayLength(nums, k) << endl; // Output: 4
  return 0;
}