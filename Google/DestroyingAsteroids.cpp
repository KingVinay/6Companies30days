#include<bits/stdc++.h>
using namespace std;

bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
    sort(asteroids.begin(),asteroids.end());
    long long int weight = mass;
    for(int i=0;i<asteroids.size();i++){
        if(asteroids[i] > weight){
            return false;
        }
        weight += asteroids[i]; 
    }

    return true;
}
int main()
{
   int mass = 5;
   vector<int> asteroids = {3,2,5,1,4};
   cout << asteroidsDestroyed(mass, asteroids) << endl;
   return 0;
}