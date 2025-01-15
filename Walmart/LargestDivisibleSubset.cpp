#include<bits/stdc++.h>
using namespace std;

vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());

        vector<int> dp(n, 1),parent(n, -1);

        int maxSize = 1;
        int lastIndex = 0;

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    parent[i] = j;
                }
            }

            if (dp[i] > maxSize) {
                maxSize = dp[i];
                lastIndex = i;
            }
        }

        vector<int> ans;
        for (int i = lastIndex; i >= 0; i = parent[i]) {
            ans.push_back(nums[i]);
            if (parent[i] == -1)
                break;
        }

        reverse(ans.begin(),ans.end());

        return ans;
    }
int main()
{
  vector<int> nums = {5,9,18,54,108,540,90,180,360,720};
  vector<int> ans = largestDivisibleSubset(nums);
  for(auto i: ans)
    cout << i << " ";
  return 0;
}