#include<bits/stdc++.h>
using namespace std;

string convertToTitle(int columnNumber) {

        string ans = "";

        if(columnNumber>=1 && columnNumber<=26){
            char c = 64 + columnNumber;
            ans = c + ans;
            return ans;
        }

        int quotient = INT_MAX;
        int remainder;

        while(quotient > 26){
            quotient = columnNumber / 26;
            remainder = columnNumber % 26;

            if(remainder == 0){
                remainder = 26;
                quotient -= 1;
            }

            char c = remainder + 64;
            ans = c + ans;

            if(quotient > 26){
                columnNumber = quotient;
            }
        }

        char c = quotient + 64;
        ans = c + ans;

        return ans;
    }

int main()
{
   int n;
   cout<<"Enter the column number: ";
   cin>>n;
   cout<<"The title of the column is: "<<convertToTitle(n);
   return 0;  
}