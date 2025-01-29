#include<bits/stdc++.h>
using namespace std;

int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
    int ans = 0;
    for(int i=0;i<arr1.size();i++){
        for(int j=0;j<arr2.size();j++){
            int x = abs(arr1[i] - arr2[j]);
            if(x<=d){
                ans++;
                break;
            }
        }
    }

    return (arr1.size() - ans);
}

int main()
{
   vector<int> arr1 = {1,4,8,10,20};
   vector<int> arr2 = {4,10,15,20,30};
   int d = 2;
   cout << findTheDistanceValue(arr1, arr2, d) << endl;
   return 0;
}