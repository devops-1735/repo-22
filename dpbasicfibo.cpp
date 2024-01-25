#include <bits/stdc++.h>
using namespace std;
// int fibo(int n , vector<int> &dp){
//    if(n <= 1)return n;
//    if(dp[n] != -1)return dp[n];

//    dp[n] = fibo(n-1 , dp) + fibo(n-2 , dp);

//    return dp[n];
// }
int main()
{
    int n;
    cin >> n;
    // vector<int> dp(n + 1 , -1);
    // cout<<fibo(n , dp);
    int prev2 = 0;
    int prev = 1;
    int curri;
    for (int i = 2; i <= n; i++)
    {
        curri = prev + prev2;
        prev2 = prev;
        prev = curri;
    }
    cout << curri;
    return 0;
}