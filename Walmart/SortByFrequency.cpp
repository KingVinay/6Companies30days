#include<bits/stdc++.h>
using namespace std;

string frequencySort(string s) {
        unordered_map<char,int> mp;
        for(int i=0;i<s.length();i++){
            mp[s[i]] += 1;
        }

        vector<pair<char,int>> a;
        for(auto i:mp){
            a.push_back(i);
        }

        sort(a.begin(),a.end(),[](pair<char,int>&x,pair<char,int>&y){
            return x.second > y.second;
        });

        string ans="";

        for(int i=0;i<a.size();i++){
            ans.append(a[i].second,a[i].first);
        }
        return ans;
    }

int main()
{
  string s = "trtreqw3242424terwtwetee";
  cout << frequencySort(s) << endl;
  return 0;
}