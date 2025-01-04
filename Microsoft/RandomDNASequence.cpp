#include<bits/stdc++.h>
using namespace std;

vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string,int> mp;
        vector<string> ans;

        if(s.length() <= 10){
            return ans;
        }

        for(int head=0 ;head<=s.length() - 10;head++){
            string str = s.substr(head,10);
            mp[str]++;
        }

        for(auto i: mp){
            if(i.second > 1){
                ans.push_back(i.first);
            } 
        }

        return ans;
    }

int main()
{
  string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
  vector<string> ans = findRepeatedDnaSequences(s);
  for(auto str: ans){
    cout << str << endl;
  }
  return 0;
}