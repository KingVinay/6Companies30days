#include<bits/stdc++.h>
using namespace std;
int getMask(string& s) {
        int mask = 0;
        for (char c : s)
            mask ^= 1 << c - 'a';
        return mask;
    }
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        int ans = 0;
        unordered_set<int> seen;

        for (string& w : startWords)
            seen.insert(getMask(w));

        for (string& w : targetWords) {
            int mask = getMask(w);
            for (char c : w)
                if (seen.contains(mask ^ 1 << c - 'a')) {
                    ++ans;
                    break;
                }
        }

        return ans;
    }
int main()
{
  vector<string> startWords = {"abc", "def", "ghi"};
  vector<string> targetWords = {"abcd", "efg", "hij"};
  cout << wordCount(startWords, targetWords) << endl; // Output: 2
  return 0;
}