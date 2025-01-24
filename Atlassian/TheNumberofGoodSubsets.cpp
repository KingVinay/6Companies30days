#include<bits/stdc++.h>
using namespace std;

int numberOfGoodSubsets(vector<int>& nums) {
        int primes[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

        int count[31] = {};
        for (int x : nums) {
            ++count[x];
        }

        int numPrimes = 10;
        const int mod = 1e9 + 7;

        vector<long long> dp(1 << numPrimes);
        dp[0] = 1;

        
        for (int i = 0; i < count[1]; ++i) {
            dp[0] = dp[0] * 2 % mod;
        }

        for (int x = 2; x < 31; ++x) {
            if (count[x] == 0 || x % 4 == 0 || x % 9 == 0 || x % 25 == 0) {
                continue;
            }

            int mask = 0;
            for (int i = 0; i < numPrimes; ++i) {
                if (x % primes[i] == 0) {
                    mask |= 1 << i;
                }
            }
            
            for (int state = (1 << numPrimes) - 1; state > 0; --state) {
                if ((state & mask) == mask) {
                    dp[state] = (dp[state] + (long long)(count[x]) * dp[state ^ mask]) % mod;
                }
            }
        }

        long long answer = 0;
        for (int i = 1; i < (1 << numPrimes); ++i) {
            answer = (answer + dp[i]) % mod;
        }

        return (int)(answer);
    }

int main()
{
    vector<int> nums = {1,2,3,4};
    cout<<numberOfGoodSubsets(nums)<<endl;
    return 0;
}