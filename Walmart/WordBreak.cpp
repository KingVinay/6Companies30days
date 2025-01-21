#include<bits/stdc++.h>
using namespace std;

bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> word_set(wordDict.begin(), wordDict.end());

        int strLength = s.length();

        vector<bool> canSegment(strLength+1);

        for (int i = 0; i < sizeof(canSegment) / sizeof(canSegment[0]); ++i) {
            canSegment[i] = false;
        }
        canSegment[0] = true;

        for (int i = 1; i <= strLength; ++i) {
            for (int j = 0; j < i; ++j) {
                if (canSegment[j] && word_set.count(s.substr(j, i - j))) {
                    canSegment[i] = true;
                    break;
                }
            }
        }

        return canSegment[strLength];
    }

int main()
{
  string s = "leetcode";
  vector<string> wordDict = {"leet", "code"};
  cout << wordBreak(s, wordDict) << endl;
  return 0;
}