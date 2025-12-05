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
const int N = 1e6;
int dp[N];
int MOD = 1e9 + 7;
/**
 *
 * Great Realization in this one we can arrive at solution in the following manner:
 *  suppose target is k we could have arrived from (k-1,k-2,k-3...k-6) depending upon the
 *
 *  value we rolled. so $dp[k] =\sum_{i=1}^{6}dp[k-i]$.
 *
 * Also note: we only take till value of k is $\geq$ 6. else we'll not pick that.
 *
 */

void solve()
{
    int n;
    cin >> n;
    dp[0] = 1;
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= 6 ; j++){
            if(i-j>=0) dp[i] = (dp[i]+dp[i-j]) % MOD;
        }
    }
    cout << dp[n] ;
}

int32_t main()
{
    fastio();
    {
        solve();
    }
    return 0;
}