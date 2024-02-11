#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define rrep(i, a, b) for (int i = a-1; i >=b; --i)
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
using namespace std;
# define mod 998244353

int sol(int i, unordered_map<int, int>& h,int dp[],int n)
{
	if (i >= n) return 0;

	else if (dp[i] != -1)
		return dp[i];

	int min_value = INT_MAX;

	for (int j = 1; j <= 6; j++) {

		int k = i + j;
		if (h.count(k) > 0) {
			if (h[k] < k) continue;
			k = h[k];
		}
		min_value = min(min_value, sol(k, h, dp, n) + 1);
	}
	dp[i] = min_value;
	return dp[i];
}


int main()
{
    freopen("test_cases_Q2.txt", "r", stdin);
    freopen("output_Q2.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    while (tt--)
    {
	    int n,m; cin>>n>>m; int dp[n+1];
        rep(i,0,n+1){
	    	dp[i] = -1;
	    }
	    unordered_map<int, int> h;
	    rep(i,0,m){
            int x,y; cin>>x>>y;
	    	h[x] = y;
	    }
    
        cout << "Min Dice throws required is "<< sol(1, h, dp,n) << endl;
    }
	return 0;
}
