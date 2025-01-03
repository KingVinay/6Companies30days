#include<bits/stdc++.h>
using namespace std;

static bool compareEnvelopes(vector<int>&a, vector<int>&b){
        if(a[0]==b[0]){
            return a[1] > b[1];
        }

        return a[0] < b[0];
    }

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(),envelopes.end(),compareEnvelopes);

        vector<int> ans;
        for(auto envelope : envelopes){
            int h = envelope[1];
            auto it = lower_bound(ans.begin(), ans.end(), h);

            if(it == ans.end()){
                ans.push_back(h);
            }else{
                *it = h;
            }
        }

        return ans.size();
    }

int main(){
  vector<vector<int>> envelopes = {{5,4},{6,4},{6,7},{2,3}};
  cout << maxEnvelopes(envelopes) << endl;
  return 0;
}