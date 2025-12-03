#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100;
bool found[MAXN];
int memo[MAXN];

int f(int n){
  if(found[n]) return memo[n];
  if(n == 0) return 0;
  if(n == 1) return 1;
  found[n] = 1;
  memo[n] = f(n-1) + f(n-2);
  return memo[n];
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
    cout << f(80) << endl;
    return 0;
}