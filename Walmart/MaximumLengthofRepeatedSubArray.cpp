#include<bits/stdc++.h>
using namespace std;

// O(n^2) time complexity using dp

int findLength(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();

        vector<int> dp(n + 1, 0);

        int maxLength = 0;

        for (int i = 1; i <= m; ++i) {
            vector<int> newDp(n + 1, 0);

            for (int j = 1; j <= n; ++j) {
                if (nums1[i - 1] == nums2[j - 1]) {
                    newDp[j] = dp[j - 1] + 1;
                    maxLength = max(maxLength, newDp[j]);
                }
            }

            dp = newDp;
        }

        return maxLength;
    }

// O(n^2 * logn) time complexity

int findLength(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<string,int> st1,st2;

        for(int i=0;i<nums1.size();i++){
            string s = "";
            s += to_string(nums1[i]);
            st1[s] = 1;
            for(int j=i+1;j<nums1.size();j++){
                s += " " + to_string(nums1[j]);
                st1[s] = j-i+1;
            }
        }

        for(int i=0;i<nums2.size();i++){
            string s = "";
            s += to_string(nums2[i]);
            st2[s] = 1;
            for(int j=i+1;j<nums2.size();j++){
                s += " " + to_string(nums2[j]);
                st2[s] = j-i+1;
            }
        }

        int ans = 0;

        for(auto i: st1){
            if(st2.find(i.first)!=st2.end()){
                ans = max(ans,i.second);
            }
        }

        return ans;

    }
int main()
{
  vector<int> nums1 = {1,2,3,2,1};
  vector<int> nums2 = {3,2,1,4,7};
  cout << findLength(nums1,nums2) << endl;
  return 0;
}