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

const int N = 1e5 + 5;
ll dp[N];

void solve()
{
    int n, W;
    cin >> n >> W;
    vector<int> w(n), v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> w[i] >> v[i];
    }
    for (int i = 0; i < n; i++)
        for (int j = W; j >= w[i]; j--)
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
    cout << dp[W];
}

int32_t main()
{
    fastio();
    {
        solve();
    }
    return 0;
}