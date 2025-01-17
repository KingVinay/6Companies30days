#include<bits/stdc++.h>
using namespace std;

// O(n^2) Solution using 2 nested loops

int numFriendRequests(vector<int>& ages) {
        int ans = 0;
        for(int i=0;i<ages.size();i++){
            int agex = ages[i];
            for(int j=0;j<ages.size();j++){
                if(i==j){
                    continue;
                }else{
                   int agey = ages[j];
                   bool condition1 = ((0.5 * agex + 7) >= agey);
                   bool condition2 = (agex < agey);
                   bool condition3 = (agey > 100) && (agex < 100);

                   if(condition1 || condition2 || condition3){
                        continue;
                   }else{
                        ans++;
                   }
                }
            }
        }

        return ans;
    }

int main()
{
  vector<int> ages = {20,30,100,110,120};
  cout << numFriendRequests(ages) << endl;
  return 0;
}