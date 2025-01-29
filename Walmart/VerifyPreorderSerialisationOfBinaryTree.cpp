#include<bits/stdc++.h>
using namespace std;

bool isValidSerialization(string preorder) {
        int nos = 0,hash = 0;
        for(int i=0;i<preorder.length();i++){
            if(preorder[i] == '#'){
                hash++;
            }else if(preorder[i] == ','){
                continue;
            }
            else{
                if(i==0 || preorder[i-1] == ','){
                    nos++;
                }
            }

            if(nos < hash && i != preorder.length() - 1){
                return false;
            }
        }

        if(hash != (nos+1)){
            return false;
        }
        return true;
    }
int main()
{
    string preorder = "9,3,4,#,#,1,#,#,2,#,6,#,#";
    cout << isValidSerialization(preorder) << endl;
    return 0;
}