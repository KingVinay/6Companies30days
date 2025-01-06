#include<bits/stdc++.h>
using namespace std;
int getStartIndex(const vector<int>& nums) {
    for (int i = nums.size() - 2; i >= 0; --i)
      if (nums[i] >= nums[i + 1])
        return i + 1;
    return 0;
  }

  int incremovableSubarrayCount(vector<int>& nums) {
    int n = nums.size();
    int startIndex = getStartIndex(nums);

    if (startIndex == 0)
      return n * (n + 1) / 2;

    int ans = n - startIndex + 1;

    for (int i = 0, j = startIndex; i < startIndex; ++i) {
      if (i > 0 && nums[i] <= nums[i - 1])
        break;
      while (j < n && nums[i] >= nums[j])
        ++j;
      ans += n - j + 1;
    }

    return ans;
  }
int main()
{
  vector<int> nums = {1,3,2,4,5};
  cout << incremovableSubarrayCount(nums) << endl;
  return 0;
}
