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

/**
 * This is also similar to dicey problem but here we have to be careful
 * as we are adding coins not there value so for target = k; and coins {1,2,3}
 * we can come from if last coin was 1 we came from dp[k-1] & total coins would've been
 * equal to dp[k-1]+1. and similarly for dp[k-2]+1 and dp[k-3]+1. so we find which of the
 * follwing requires the least number of coins from {dp[k-1],dp[k-2],dp[k-3]} and add 1.
 */

void solve()
{
    const int N = 1e6;
    vector<int> dp(N,-1);

    int n,k;
    cin >> n >> k;
    vector<int> arr(n);
    for(auto & x : arr) cin >> x;
    //dp[i] == minimum number of coins to reach till ith sum we need to find dp[k]
    dp[0] = 0;
    for( int i = 1 ; i <= k ; i++){
        int minsum = INT_MAX;
        for( int j = 0 ; j < n ; j++){
            if(arr[j] <= i && dp[i-arr[j]] != -1) minsum = min(minsum,dp[i-arr[j]]);
        }
        if(minsum != INT_MAX) dp[i] = minsum + 1; //important as sometimes minsum == INT_MAX
    }
    cout << dp[k];
}

int32_t main()
{
    fastio();
    {
        solve();
    }
    return 0;
}