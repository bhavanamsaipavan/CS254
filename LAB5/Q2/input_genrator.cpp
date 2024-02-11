#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef long double ld;
using namespace std;
#define lmt 100
int main()
{
    freopen("test_cases_Q2.txt","w",stdout);
    
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tt = rand()%lmt;
	cout<<tt<<"\n";
	while (tt--)
	{
        int n=rand()%lmt,m=rand()%(n/2);  cout<<n<<" "<<m<<"\n";
		map<int,int> mp;
		rep(i,0,m){ mp[rand()%(n-1) + 1] = rand()%(n-1) + 1; }
        for(auto x : mp){
			cout<<x.first<<" "<<x.second<<"  ";
		}   cout<<"\n\n";
	}
}