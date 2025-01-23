#include<bits/stdc++.h>
using namespace std;

int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        int n = aliceValues.size();
        
        vector<pair<int, int>> valuePairs(n);
        for (int i = 0; i < n; ++i) {
            valuePairs[i] = {aliceValues[i] + bobValues[i], i}; 
        }

        sort(valuePairs.rbegin(), valuePairs.rend());

        int aliceScore = 0, bobScore = 0;

        for (int i = 0; i < n; ++i) {
            int index = valuePairs[i].second; 
            
            if (i % 2 == 0) {
                aliceScore += aliceValues[index]; 
            } else {
                bobScore += bobValues[index]; 
            }
        }

        if (aliceScore == bobScore) return 0; 
        return aliceScore > bobScore ? 1 : -1;
    }

int main()
{
  vector<int> aliceValues = {1,3};
  vector<int> bobValues = {2,1};
  cout << stoneGameVI(aliceValues, bobValues) << endl;
  return 0;
}