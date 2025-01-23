#include<bits/stdc++.h>
using namespace std;

vector<int> smallestTrimmedNumbers(vector<string>& nums,
                                       vector<vector<int>>& queries) {
        int numOfNumbers = nums.size();
        vector<pair<string, int>> trimmedNumbers(numOfNumbers);
        vector<int> answer;

        for (auto& query : queries) {
            int k = query[0];
            int trimLength = query[1];

            for (int i = 0; i < numOfNumbers; ++i) {
                trimmedNumbers[i] = {
                    nums[i].substr(nums[i].size() - trimLength), i};
            }

            sort(trimmedNumbers.begin(), trimmedNumbers.end());

            answer.push_back(trimmedNumbers[k - 1].second);
        }

        return answer;
    }

int main()
{
  vector<string> nums = {"abc","deq","xy","z","ghi"};
  vector<vector<int>> queries = {{1, 1},{1, 2},{3, 2},{2, 3}};
  vector<int> result = smallestTrimmedNumbers(nums, queries);
  for (int i : result) {
    cout << i << " ";
  }
  cout << endl;
  return 0;
}