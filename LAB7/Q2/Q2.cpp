#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<long long, long long>
using namespace std;

bool compare(pll a, pll b){
    return a > b;
}

void solve() {
    int n;
    cin >> n;

    vector<int> dead_line(n), profit(n);

    for(int i = 0; i < n; i++){
        cin >> dead_line[i];
    }   

    for(int i = 0; i < n; i++){
        cin >> profit[i];
    }

    vector<pii> p(n);

    for(int i = 0; i < n; i++){
        p[i] = {profit[i], dead_line[i]};
    }

    sort(p.begin(), p.end(), compare);

    vector<bool> visited(n, false);

    int count = 0, ans = 0;

    for(int i = 0; i < n; i++){
        for(int j = min(n, p[i].second)-1; j >= 0; j--){
            if(!visited[j]){
                visited[j] = true;
                count++;
                ans += p[i].first;
                break;
            }
        }
    }

    cout << count << " " << ans;
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