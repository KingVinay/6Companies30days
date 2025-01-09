#include<bits/stdc++.h>
using namespace std;

long long maximumSubarraySum(vector<int>& arr, int k) {
        unordered_map<int, int> mp;
        long long currentSum = 0, maxSum = 0;
        int n = arr.size(), left = 0, i = 0;

        while (i < k && i < n) {

            currentSum += arr[i];
            mp[arr[i]]++;

            i++;
        }

        if (mp.size() == k) {
            maxSum = currentSum;
        }

        for (int i = k; i < n; i++) {

            mp[arr[i]]++;
            mp[arr[left]]--;
            if (mp[arr[left]] == 0) {
                mp.erase(arr[left]);
            }
            currentSum += arr[i];
            currentSum -= arr[left];
            if (mp.size() == k) {
                maxSum = max(maxSum, currentSum);
            }
            ++left;
        }

        return maxSum;
    }
int main()
{
  vector<int> arr = {1, 4, 2, 10, 23, 3, 1, 0, 20};
  int k = 4;
  cout << maximumSubarraySum(arr, k) << endl;
  return 0;
}