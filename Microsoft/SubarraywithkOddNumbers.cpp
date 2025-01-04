#include<bits/stdc++.h>
using namespace std;

int atmostsubarray(vector<int>nums, int k){
        int head=0,tail=0,sum=0;
        int count = 0;
        for(;head<nums.size();head++){
            sum += nums[head]%2;

            while(sum > k && tail<=head){
                sum -= nums[tail]%2;
                tail++; 
            }

            count += head - tail + 1;
        }

        return count;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return atmostsubarray(nums,k) - atmostsubarray(nums,k-1);
    }

int main()
{
  vector<int> nums = {1,1,1,0,0,0,1,1,1,1,0};
  int k = 2;
  cout << numberOfSubarrays(nums, k) << endl;
  return 0;
}