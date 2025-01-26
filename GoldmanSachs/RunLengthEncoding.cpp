#include<bits/stdc++.h>
using namespace std;

string encode(string s) {
        // code here
        int n = s.length();
        string ans = "";
        for (int i = 0; i < n; i++) {
            int count = 1;
            while (i < n - 1 && s[i] == s[i + 1]) {
                count++;
                i++;
            }
            ans += s[i] + to_string(count);
        }
        return ans;
    }

int main()
{
  string s = "wwwwaaadexxxxxx";
  cout << encode(s) << endl; // Output: w4a3d1e1x6
  return 0;
}