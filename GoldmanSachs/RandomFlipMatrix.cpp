#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    set<pair<int,int>> s;
    int r,c;

    Solution(int m, int n) {
        r=m;
        c=n;
    }
    
    vector<int> flip() {
        int x = rand()%r;
        int y = rand()%c;
        if(!s.count({x,y})){
            s.insert({x,y});
            return {x,y};
        }
        return flip();
    }
    
    void reset() {
        s.clear();
    }
};

int main()
{
  Solution obj(3, 3);
  vector<int> param_1 = obj.flip();
  vector<int> param_2 = obj.flip();
  vector<int> param_3 = obj.flip();
  obj.reset();
  vector<int> param_4 = obj.flip();
  return 0;
}