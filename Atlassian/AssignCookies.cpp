#include<bits/stdc++.h>
using namespace std;

int findContentChildren(vector<int>& g, vector<int>& s) {
        int ans = 0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());

        int i = g.size() - 1, j = s.size() - 1;
        if(j < 0){return ans;}
        while(i>=0 && j>=0){
            if(s[j]>=g[i]){
                ans++;
                j--;
            }
            i--;
        }

        return ans;
    }

int main()
{
  vector<int> g = {1,2,3};
  vector<int> s = {3};
  cout << findContentChildren(g, s) << endl; // Output: 1
  return 0;
}