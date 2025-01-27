#include<bits/stdc++.h>
using namespace std;

vector<int> findTwoElement(vector<int>& arr) {
        // code here
        int mx = *max_element(arr.begin(),arr.end());
        vector<int> range(arr.size() + 1,0);
        for(int i=0;i<arr.size();i++){
            range[arr[i]]++;
        }
        
        int a,b;
        
        for(int i=1;i<range.size();i++){
            if(range[i]>1){
                b = i;
            }
            else if(range[i] == 0){
                a = i;
            }
        }
        
        return {b,a};
        
    }

int main()
{
  vector<int> arr = {4, 3, 6, 2, 1, 1};
  vector<int> result = findTwoElement(arr);
  for (int i : result) {
    cout << i << " ";
  }
  cout << endl;
  return 0;
}