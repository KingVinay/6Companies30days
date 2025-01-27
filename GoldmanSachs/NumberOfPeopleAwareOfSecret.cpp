#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD 1000000007

int peopleAwareOfSecret(int n, int delay, int forget) {
        int arraySize = (n << 1) + 10;
      
        vector<ll> incrementArray(arraySize, 0);
        vector<ll> peopleCountArray(arraySize, 0); 

        peopleCountArray[1] = 1;

        for (int day = 1; day <= n; ++day) {
            if (!peopleCountArray[day]) continue;
            incrementArray[day] = (incrementArray[day] + peopleCountArray[day]) % MOD;
            incrementArray[day + forget] = (incrementArray[day + forget] - peopleCountArray[day] + MOD) % MOD;
          
            int shareDay = day + delay;
            while (shareDay < day + forget) {
                peopleCountArray[shareDay] = (peopleCountArray[shareDay] + peopleCountArray[day]) % MOD;
                ++shareDay;
            }
        }
      
        int totalAwarePeople = 0;
        for (int day = 1; day <= n; ++day) {
            totalAwarePeople = (totalAwarePeople + incrementArray[day]) % MOD;
        }
        return totalAwarePeople;
    }

int main()
{
  int n = 5, delay = 2, forget = 3;
  int ans = peopleAwareOfSecret(n, delay, forget);
  cout << ans << endl;
  return 0;
}