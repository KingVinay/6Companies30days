#include<bits/stdc++.h>
using namespace std;

class ThroneInheritance {
public:
    ThroneInheritance(string kingName) : kingName(kingName) {}

    void birth(string parentName, string childName) {
        family[parentName].push_back(childName);
    }

    void death(string name) { dead.insert(name); }

    vector<string> getInheritanceOrder() {
        vector<string> ans;
        dfs(kingName, ans);
        return ans;
    }

private:
    unordered_set<string> dead;
    unordered_map<string, vector<string>> family;
    string kingName;

    void dfs(const string& name, vector<string>& ans) {
        // if (!dead.contains(name))
            ans.push_back(name);
        // if (!family.contains(name))
            return;

        for (const string& child : family[name])
            dfs(child, ans);
    }
};

int main()
{
  ThroneInheritance t("king");
  t.birth("king", "andy");
  t.birth("king", "bob");
  t.birth("king", "catherine");
  t.birth("andy", "matthew");
  t.birth("bob", "joe");
  t.birth("bob", "diana");
  t.birth("catherine", "herbert");
  t.death("bob");
  t.death("diana");
  vector<string> ans = t.getInheritanceOrder();
  for (auto& name : ans)
    cout << name << " ";
  cout << endl; // Output: king catherine matthew joe andy herbert
  return 0;
}

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */