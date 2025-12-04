/*
    Author: priycosthu-codes
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

/**
 * Great question as compared to frog-1 in this we had to check the previous k states from
 * each i till possible bounds if there exist a min cost value then we had to pick that
 * value for our use.
 */

void solve()
{
    int n,k;
    cin >> n >> k;
    vector<int> height(n);
    for(auto & x : height) cin >> x;
    dp[0] = 0;
    for(int i = 1 ; i < n ; i++){
        int cost = INT_MAX;
        for(int j = 1; j <= k; j++){
            if(i-j>=0){
                cost = min(cost, dp[i-j] + abs(height[i] - height[i-j]));
            }else break;
        }
        dp[i] = cost;
    }
    cout << dp[n-1] << endl;
}

int32_t main()
{
    fastio();
    {
        solve();
    }
    return 0;
}