#include<bits/stdc++.h>
using namespace std;

vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        // code here
        if(k==1){
            return arr;
        }
        
        vector<int> res;
        
        int currmax = 0;
        int left = 0;
        
        unordered_map<int,int> mp;
        for(int i=0;i<k;i++){
           currmax =  max(arr[i],currmax);
           mp[arr[i]]++;
        }
        res.push_back(currmax);
        
        for(int i=k;i<arr.size();i++){
            mp[arr[left]]--;
            if(arr[left] == currmax){
                currmax = 0;
                int j;
                for(j=left+1;j<=left+k && j<arr.size();j++){
                    currmax = max(arr[j], currmax);
                    mp[arr[j]]++;
                }
                i=j-1;
            }
            
            if(mp[arr[left]]==0){
                mp.erase(arr[left]);
            }
            left++;
            currmax = max(arr[i], currmax);
            res.push_back(currmax);
        }
        
        return res;
    }
int main()
{
  vector<int> arr = {1, 3, 1, 2, 4, 3, 5, 6, 7, 8, 9};
  int k = 3;
  vector<int> ans = maxOfSubarrays(arr, k);
  for(int i=0;i<ans.size();i++){
    cout << ans[i] << " ";
  }
  return 0;
}