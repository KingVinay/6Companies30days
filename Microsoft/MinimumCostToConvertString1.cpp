#include<bits/stdc++.h>
using namespace std;

long long minimumCost(string source, string target, vector<char>& original,
                          vector<char>& changed, vector<int>& cost) {
        vector<vector<long>> dist(26, vector<long>(26, LONG_MAX));

        for (int i = 0; i < cost.size(); i++) {
            int m = original[i] - 'a';
            int n = changed[i] - 'a';

            dist[m][n] = min(dist[m][n], (long)cost[i]);
        }

        for (int k = 0; k < 26; k++) {
            for (int i = 0; i < 26; i++) {
                if (dist[i][k] < LONG_MAX) {
                    for (int j = 0; j < 26; j++) {
                        if (dist[k][j] < LONG_MAX) {
                            dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                        }
                    }
                }
            }
        }

        long ans = 0;

        for(int i=0;i<source.size();i++){
            int m = source[i]-'a';
            int n = target[i]-'a';

            if(m==n){
                continue;
            }

            if(dist[m][n] == LONG_MAX){
                return -1;
            }
            ans+= dist[m][n];
        }

        return (long long) ans;
    }

int main()
{
  string source = "aba", target = "bbb";
  vector<char> original = {'a', 'b', 'a'};
  vector<char> changed = {'b', 'c', 'b'};
  vector<int> cost = {5, 2, 4};

  cout << minimumCost(source, target, original, changed, cost) << endl;

  return 0;
}