#include<bits/stdc++.h>
using namespace std;

int firstUniqChar(string s) {
        vector<int> a(26,0);
        for(char c: s){
            a[c - '0']++;
        }

        for(int i=0;i<s.length();i++){
            if(a[s[i] - '0'] == 1){
                return i;
            }
        }
        return -1;
    }

int main()
{
  string s = "loveleetcode";
  cout << firstUniqChar(s) << endl;
  return 0;
}