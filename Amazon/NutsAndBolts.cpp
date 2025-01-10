#include<bits/stdc++.h>
using namespace std;

void matchPairs(int n, char nuts[], char bolts[]) {
        // code here
        unordered_map<char,int> mp;
        vector<char> temp;
        vector<char> order = { '!', '#', '$', '%', '&', '*', '?', '@', '^' };
        
        for(int i=0;i<n;i++){
            mp[nuts[i]]++;
        }
        
        for(int i=0;i<=9;i++){
            if(mp.find(order[i])!=mp.end()){
                temp.push_back(order[i]);
            }
        }
        
        for(int i=0;i<n;i++){
            nuts[i] = temp[i];
            bolts[i] = temp[i];
        }

    }
int main()
{
  char nuts[] = {'@', '%', '$', '#', '^'};
  char bolts[] = {'%','@', '#', '$', '^'};
  int n = sizeof(nuts)/sizeof(nuts[0]);
  matchPairs(n, nuts, bolts);
  for(int i=0;i<n;i++){
    cout << nuts[i] << " ";
  }
  cout << endl;
  for(int i=0;i<n;i++){
    cout << bolts[i] << " ";
  }
  cout << endl;
  return 0;
}