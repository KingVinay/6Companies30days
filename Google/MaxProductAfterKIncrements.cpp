#include<bits/stdc++.h>
using namespace std;

int maximumProduct(vector<int>& nums, int k) {
    int Mod = 1e9 + 7;
    long ans = 1;
    priority_queue<int, vector<int>, greater<>> minHeap;

    for (int num : nums)
        minHeap.push(num);

    for (int i = 0; i < k; ++i) {
        int minNum = minHeap.top();
        minHeap.pop();
        minHeap.push(minNum + 1);
    }

    while (!minHeap.empty()) {
        ans *= minHeap.top(), minHeap.pop();
        ans %= Mod;
    }

    return ans;
}

int main()
{
    vector<int> nums = {1,2,3,4};
    int k = 5;
    cout << maximumProduct(nums, k) << endl;
    return 0;
}