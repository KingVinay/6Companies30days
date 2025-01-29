#include<bits/stdc++.h>
using namespace std;

vector<string> findHighAccessEmployee(vector<vector<string>>& access_times) {
    unordered_set<string> ans;

    sort(access_times.begin(),access_times.end());

    for (int i = 0; i + 2 < access_times.size(); ++i) {
        string& name = access_times[i][0];
        // if (ans.contains(name))
        //     continue;
        if (name != access_times[i + 2][0])
            continue;
        if (stoi(access_times[i + 2][1]) - stoi(access_times[i][1]) < 100)
            ans.insert(name);
    }

    return {ans.begin(), ans.end()};
}

int main()
{
   vector<vector<string>> access_times = {{"Alice", "15:58", "15:59"}, {"Bob", "15:57", "15:59"}, {"Alice", "15:56", "15:58"}, {"Bob", "15:55", "15:57"}};
   vector<string> result = findHighAccessEmployee(access_times);
   for(auto name : result) {
      cout << name << " ";
   }
   cout << endl;
   return 0;
}