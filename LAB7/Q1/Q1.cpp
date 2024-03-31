#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<long long, long long>
using namespace std;

int max_profit_greedy(vector<int> &prices, vector<int> &weights, int W){
    int n = prices.size();
    vector<pair<double, int>> p(n);

    for(int i = 0; i < n; i++){
        p[i] = {prices[i]/(double)weights[i], i};
    }

    sort(p.begin(), p.end(), greater<pair<double, int>>());

    int profit = 0;
    for(int i = 0; i < n; i++){

        int idx = p[i].second;

        if(weights[idx] <= W){
            profit += prices[idx];
            W -= weights[idx];
        }
        else{
            break;
        }
    }

    return profit;
}

int max_profit(vector<int> &prices, vector<int> &weights, int W){
    int n = prices.size();
    vector<vector<int>> dp(n+1, vector<int>(W+1, 0));

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= W; j++){
            if(weights[i-1] <= j){
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-weights[i-1]] + prices[i-1]);
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[n][W];
}

void solve() {
    int n, W;
    cin >> n >> W;

    vector<int> prices(n), weights(n);

    for(int i = 0; i < n; i++){
        cin >> prices[i];
    }

    for(int i = 0; i < n; i++){
        cin >> weights[i];
    }

    cout <<"Profit using DP is " << max_profit(prices, weights, W) << endl;
    cout <<"Profit using Greedy is " << max_profit_greedy(prices, weights, W);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t ;
    cin >> t;

    while (t--)
    {
        solve();
        cout << endl;
    }

    return 0;
}