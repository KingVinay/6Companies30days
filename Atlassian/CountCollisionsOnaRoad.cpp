#include<bits/stdc++.h>
using namespace std;

int countCollisions(string directions) {
        
        int leftIndex = 0, rightIndex = directions.size() - 1;
        int collisionCount = 0;

        while (leftIndex <= rightIndex && directions[leftIndex] == 'L') {
            leftIndex++;
        }

        while (leftIndex <= rightIndex && directions[rightIndex] == 'R') {
            rightIndex--;
        }

        for (int i = leftIndex; i <= rightIndex; i++) {
            if (directions[i] != 'S') {
                collisionCount++;
            }
        }

        return collisionCount;
    }

int main()
{
  string directions = "LRSR";
  cout << countCollisions(directions) << endl; // Output: 1
  return 0;
}