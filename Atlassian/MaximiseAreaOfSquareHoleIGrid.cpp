#include<bits/stdc++.h>
using namespace std;

int maxContinousGap(vector<int>& bars) {
        int res = 2;
        int runningGap = 2;
        sort(bars.begin(), bars.end());
        for (int i = 1; i < bars.size(); ++i) {
            runningGap = bars[i] == bars[i - 1] + 1 ? runningGap + 1 : 2;
            res = max(res, runningGap);
        }
        return res;
    }
int maximizeSquareHoleArea(int n, int m, vector<int>& hBars,
                            vector<int>& vBars) {
    int gap = min(maxContinousGap(hBars), maxContinousGap(vBars));
    return gap * gap;
}
int main()
{
  vector<int> hBars = {1, 2, 3, 4, 5};
  vector<int> vBars = {1, 2, 3, 4, 5};
  int n = 5, m = 5;
  cout << maximizeSquareHoleArea(n, m, hBars, vBars) << endl; // Output: 4
  return 0;
}