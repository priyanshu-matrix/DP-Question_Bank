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

void solve()
{
    //dp[i] represent min number of steps to make a i(num) zero
    int n;
    cin >> n;
    int m = to_string(n).length();
    vector<int> dp(n+2,INT_MAX);
    dp[0] = 0;
    for( int i = 1; i <= n ; i++){
        int x = i;
        int mn = INT_MAX;
        while(x > 0){
            int digit = x%10;
            if(digit > 0 && dp[i-digit] != INT_MAX){
                mn = min(mn,dp[i-digit]);
            }
            x /= 10;
        }
        if(mn!=INT_MAX) dp[i] = mn+1;
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