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
const int MOD = 1e9+7;
int dp[N];

/**
 * Just like dice combination in this one we can arrive at the answer from previous
 * values so we take those values which result in non-negative index and do the same procedure
 *
 * https://github.com/priyanshu-matrix/DP-Question_Bank/blob/master/Dice_Combinations.cpp
 */

void solve()
{
    int n,k;
    cin >> n >> k;
    vector<int> arr(n);
    for(auto & x : arr) cin >> x;
    dp[0] = 1;
    for( int i = 1 ; i <= k ; i++){
        for(int j = 0 ; j < n ; j++){
            if(arr[j] <= i){
                dp[i] = (dp[i]+dp[i-arr[j]])%MOD;
            }
        }
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