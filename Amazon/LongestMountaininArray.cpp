#include<bits/stdc++.h>
using namespace std;

int longestMountain(vector<int>& arr) {
        int n = arr.size();
        if (n < 3)
            return 0;
        int ans = 0;
        for (int i = 1; i <= n - 2;) {
            if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
                int count = 0;

                int j = i;

                while (j > 0 && arr[j] > arr[j - 1])
                    count++, j--;
                while (i <= n - 2 && arr[i] > arr[i + 1])
                    count++, i++;
                ans = max(ans, count);
            } else
                i++;
        }
        if (ans > 0)
            return ans + 1;
        return ans;
}

int main()
{
  vector<int> arr = {2, 1, 4, 7, 3, 2, 5};
  cout << longestMountain(arr) << endl;
  return 0;
}