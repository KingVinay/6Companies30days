#include<bits/stdc++.h>
using namespace std;

string printMinNumberForPattern(string S){
        // code here 
        string result; 
  
        stack<int> stk; 
    
        for (int i = 0; i <= S.length(); i++) 
        { 
            stk.push(i + 1); 
    
            if (i == S.length() || S[i] == 'I') 
            { 
                while (!stk.empty()) 
                {
                    result += to_string(stk.top()); 
                    stk.pop(); 
                } 
            } 
        } 
      
        return result ; 
    }

int main()
{
  string S = "IDID";
  cout << printMinNumberForPattern(S) << endl;
  return 0;
}