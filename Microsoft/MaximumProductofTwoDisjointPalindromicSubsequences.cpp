#include<bits/stdc++.h>
using namespace std;

int maxProduct(string s) {
        int n = s.length();
        int total = 1<<n;
        unordered_map<int,int> mp;
        string temp;

        for(int i=0;i<total;i++){
            temp="";
            for(int j=0;j<n;j++){
                if(i & (1<<j)){
                    temp += s[j];
                }
            }

            string revs = temp;
            reverse(revs.begin(),revs.end());

            if(temp == revs){
                mp[i] = temp.length();
            }
        }

        int ans = 0;

        for(auto i=mp.begin();i!=mp.end();i++){
            for(auto j=next(i);j!=mp.end();j++){
                if((i->first & j->first)==0){
                    ans = max(ans,i->second*j->second);
                }
            }
        }

        return ans;
    }

int main()
{
  string s = "leetcodecom";
  cout << maxProduct(s) << endl;
  return 0;
}