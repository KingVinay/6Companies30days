#include<bits/stdc++.h>
using namespace std;

int minExtraChar(string s, vector<string>& dictionary) {
        unordered_set<string> wordSet(dictionary.begin(),dictionary.end());
        int stringLength = s.size();
        vector<int> dp(stringLength + 1);
        dp[0] = 0;

        for (int i = 1; i <= stringLength; ++i) {
            dp[i] = dp[i - 1] + 1;

            for (int j = 0; j < i; ++j) {
                if (wordSet.count(s.substr(j, i - j))) {
                    dp[i] = min(dp[i], dp[j]);
                }
            }
        }

        return dp[stringLength];
    }

int main()
{
  vector<string> dictionary = {"cat", "bt", "hat", "tree"};
  string s = "catreehit";
  cout << minExtraChar(s, dictionary) << endl;
  return 0;
}