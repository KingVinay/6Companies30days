#include<bits/stdc++.h>
using namespace std;

vector<int> countSubgraphsForEachDiameter(int n,       vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        for (auto& edge : edges) {
            int u = edge[0] - 1, v = edge[1] - 1;
            graph[u].emplace_back(v);
            graph[v].emplace_back(u);
        }

        vector<int> answer(n - 1, 0);
        int nextNode = 0;
        int mask = 0;
        int maxDiameter = 0;

        function<void(int, int)> dfs = [&](int node, int distance) {
            mask ^= 1 << node;
            if (maxDiameter < distance) {
                maxDiameter = distance;
                nextNode = node;
            }
            for (int neighbor : graph[node]) {
                if (mask >> neighbor & 1) {
                    dfs(neighbor, distance + 1);
                }
            }
        };

        for (int currentMask = 1; currentMask < (1 << n); ++currentMask) {
            if ((currentMask & (currentMask - 1)) == 0) {
                continue;
            }

            mask = currentMask;
            maxDiameter = 0;
            int startNode = 31 - __builtin_clz(mask);
            dfs(startNode, 0);

            if (mask == 0) {
                mask = currentMask;
                maxDiameter = 0;
                dfs(nextNode, 0);
                ++answer[maxDiameter - 1];
            }
        }

        return answer;
    }

int main()
{
   vector<vector<int>> edges = {{1,2},{2,3},{5,6},{5,7}};
   vector<int> result = countSubgraphsForEachDiameter(8, edges);
   for(int i=0;i<result.size();i++)
       cout<<result[i]<<" ";
   return 0;
}