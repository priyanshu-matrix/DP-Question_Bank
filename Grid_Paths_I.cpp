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
int MOD = 1e9 + 7;

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> dp(n, vector<int>(n, 0));
    vector<vector<int>> arr(n , vector<int> (n));
    for(auto& a : arr){
        for(auto & x : a){
            char p;
            cin >> p;
            if(p == '*'){
                x = 0;
            }
            else x = 1;
        }
    }

    dp[0][0] = (arr[0][0] == 1) ? 1 : 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(arr[i][j] == 0) {
                dp[i][j] = 0;
                continue;
            }
            if(i == 0 && j == 0) continue;
            if(i > 0) dp[i][j] = (dp[i][j] + dp[i-1][j]) % MOD;
            if(j > 0) dp[i][j] = (dp[i][j] + dp[i][j-1]) % MOD;
        }
    }
    cout << dp[n-1][n-1] << endl;
}

int32_t main()
{
    fastio();
    {
        solve();
    }
    return 0;
}