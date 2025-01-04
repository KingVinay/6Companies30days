#include<bits/stdc++.h>
using namespace std;

// More Optimised Method

string getHint(string secret, string guess) {
        int bulls = 0, cows = 0;

        vector<int> countSecret(10,0);
        vector<int> countGuess(10,0);

        for(int i=0; i<secret.length(); i++){
            int secretDigit = secret[i] - '0';
            int guessDigit = guess[i] - '0';

            if(secretDigit == guessDigit){
                bulls++;
            }
            else{
                countSecret[secretDigit]++;
                countGuess[guessDigit]++;
            }
        }

        for(int i=0; i<10 ; i++){
            cows += min(countSecret[i], countGuess[i]);

        }

        return to_string(bulls)+"A"+to_string(cows)+"B";
        
    }

string getHint(string secret, string guess) {
        unordered_map<char,int> mp;
        for(char c: secret){
            mp[c]++;
        }
        int bulls = 0, cows = 0;

        for(char c: guess){
            if(mp.find(c) != mp.end()){
                if(mp[c]!=0){
                    cows++;
                    mp[c]--;
                }
            }
        }

        for(int i=0;i<secret.length();i++){
            if(secret[i]==guess[i]){
                bulls++;
                cows--;
            }
        }

        string ans = to_string(bulls) + "A" + to_string(cows) + "B";
        return ans;
    }
int main()
{
  string secret = "1807", guess = "7810";
  cout << getHint(secret, guess) << endl;
  return 0;
}