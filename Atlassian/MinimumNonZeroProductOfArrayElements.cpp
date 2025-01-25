#include<bits/stdc++.h>
using namespace std;

int kMod = 1e9 + 7;

long modPow(long x, long n) {
    if (n == 0)
        return 1L;
    x %= kMod;
    if (n % 2 == 1)
        return x * modPow(x, n - 1) % kMod;
    return modPow(x * x, n / 2) % kMod;
}

int minNonZeroProduct(int p) {
    const long n = 1L << p;
    const long halfCount = n / 2 - 1;
    return modPow(n - 2, halfCount) * ((n - 1) % kMod) % kMod;
}

int main()
{
  int p;
  cin>>p;
  cout << minNonZeroProduct(p) << endl;
  return 0;
}