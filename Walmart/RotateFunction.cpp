#include<bits/stdc++.h>
using namespace std;

int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();

        if(n==1){
            return 0;
        }

        int cumsum = 0;

        for(int i=0;i<n;i++){
            cumsum += nums[i];
        }

        int curr = 0;
        for(int i=0;i<n;i++){
            curr += i*nums[i];
        }

        int ans = curr;

        for(int i=1;i<n;i++){
          
          // (curr - nums[n-i]*(n-1)) => last sum - last index for this rotation times its index i.e., last index (n-1) and then all index moving one ahead so cumsum gives sum of all numbers and as last number is moved to 0 index so subtract that nums[n-i] from cumsum for this rotation.

            int next = (curr - nums[n-i]*(n-1)) + (cumsum - nums[n-i]);

            ans = max(ans,next);
            curr = next;
        }

        return ans;

    }

int main(){

}