#include<bits/stdc++.h>
using namespace std;

vector<string> letterCombinations(string digits) {
    if(digits.length()==0){
        return {};
    }

    vector<string> ans = {""};
    vector<string> letters = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

    for(char a : digits){
        vector<string> temp;
        for(string b : ans){
            for(char c : letters[a - '0']){
                string t = b + c;
                temp.push_back(t);
            }
        }
        ans = temp;
    }

    return ans;
}

int main()
{
  string digits = "234";
  vector<string> ans = letterCombinations(digits);
  for(auto str: ans){
    cout << str << endl;
  }
  return 0;
}