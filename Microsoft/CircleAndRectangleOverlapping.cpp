#include <bits/stdc++.h>
using namespace std;

bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int closex = max(x1, min(xCenter,x2));
        int closey = max(y1, min(yCenter,y2));

        int distx = xCenter - closex;
        int disty = yCenter - closey;

        return ((distx * distx) + (disty * disty)) <= (radius * radius);
}

int main(){
  int radius,xCenter,yCenter,x1,y1,x2,y2;
  cin >> radius >> xCenter >> yCenter >> x1 >> y1 >> x2 >> y2;

  bool overlap = checkOverlap(radius, xCenter, yCenter, x1, y1, x2, y2);

  if (overlap) {
    cout << "true" << endl;
  } else {
    cout << "false" << endl;
  }

  return 0;
}