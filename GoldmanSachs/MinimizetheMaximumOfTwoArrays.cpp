#include<bits/stdc++.h>
using namespace std;

int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {
        long left = 1, right = 1e10;
        long leastCommonMultiple = lcm((long)(divisor1),(long)(divisor2));

        while (left < right) {
            long mid = (left + right) / 2;

            long count1 = mid / divisor1 * (divisor1 - 1) + mid % divisor1;
            long count2 = mid / divisor2 * (divisor2 - 1) + mid % divisor2;

            long combinedCount = mid / leastCommonMultiple * (leastCommonMultiple - 1) + mid % leastCommonMultiple;

            if (count1 >= uniqueCnt1 && count2 >= uniqueCnt2 && combinedCount >= uniqueCnt1 + uniqueCnt2) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }

int main()
{
   int divisor1 = 5, divisor2 = 7, uniqueCnt1 = 4, uniqueCnt2 = 3;
   int ans = minimizeSet(divisor1, divisor2, uniqueCnt1, uniqueCnt2);
   cout << ans << endl;
   return 0;
}