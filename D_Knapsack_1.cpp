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
 * 2-D approach more clear to me than 1-D approach as shown on CP_Algorithms
 *  dp[i] = max(dp[i-1][W_i] + dp[i-1][W_i-w_i]+val[i])
 */

void solve()
{
    int n, W;
    cin >> n >> W;
    vector<vector<ll>> dp(n, vector<ll>(W + 1, 0));
    vector<ll> val(n), wt(n);
    for (int i = 0; i < n; i++)
    {
        cin >> wt[i] >> val[i];
    }
    for (int w = 0; w <= W; w++)
    {
        if (wt[0] <= w) dp[0][w] = val[0];
    }

    for (int i = 1; i < n; i++)
    {
        for(int w = 0; w <= W; w++){
            //Don't take
            ll notTake = dp[i-1][w];
            ll take = LLONG_MIN;
            //take
            if(wt[i] <= w){
                take = dp[i-1][w-wt[i]] + val[i];
            }
            dp[i][w] = max(take,notTake);
        }
    }
    cout << dp[n-1][W];
}

int32_t main()
{
    fastio();
    solve();
    return 0;
}