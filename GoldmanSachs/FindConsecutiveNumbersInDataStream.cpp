#include<bits/stdc++.h>
using namespace std;

class DataStream {
public:
    int val, count = 0, size;
    DataStream(int value, int k) {
        val = value;
        size = k;
    }

    bool consec(int num) {
        if (num == val) {
            count++;
        } else {
            count = 0;
        }

        if (count >= size) {
            return true;
        }
        return false;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */

int main()
{
    DataStream* obj = new DataStream(5, 1);
    cout << obj->consec(5) << endl;
    cout << obj->consec(4) << endl;
    cout << obj->consec(5) << endl;
    cout << obj->consec(2) << endl;

    return 0;  
}