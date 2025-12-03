/*
    Author: priyanshu-codes
*/


#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fastio()                 \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);
#define endl '\n'
#define all(x) x.begin(), x.end()
#define pb emplace_back
#define mp make_pair

const int N = 1e7;
int dp[N];

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(auto & x : arr) cin >> x;
    dp[0] = 0;
    dp[1] = abs(arr[1]-arr[0]);
    for(int i = 2 ; i < n ; i++){
        dp[i] = min((dp[i-1] + abs(arr[i]-arr[i-1])),(dp[i-2]+abs(arr[i]-arr[i-2])));
    }
    cout << dp[n-1];
}

int32_t main()
{
    fastio();
    {
        solve();
    }
    return 0;
}