#include<bits/stdc++.h>
using namespace std;

vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> mp;
        for(int i=0;i<words.size();i++){
            mp[words[i]]++;
        }

        vector<pair<string,int>> check;
        for(auto i: mp){
            check.push_back(i);
        }

        sort(check.begin(),check.end(),[](pair<string,int> a, pair<string,int> b){
            if(a.second == b.second){return a.first < b.first;}
            return a.second > b.second;
        });

        vector<string> ans;

        for(auto i: check){
            if(k>0){
                ans.push_back(i.first);
                k--;
            }
        }

        return ans;
    }

int main()
{
  vector<string> words = {"i", "love", "leetcode", "i", "love", "coding"};
  int k = 2;
  vector<string> ans = topKFrequent(words, k);
  for(auto str: ans){
    cout << str << " ";
  }
  return 0;
}