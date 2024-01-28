#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef long double ld;
using namespace std;

struct Node {
    int ms;
    int mp;
    int mss;
    int tsum;
};

Node getNode(int x) {
    Node a;
    a.ms = x;
    a.mp = x;
    a.mss = x;
    a.tsum = x;
    return a;
}

Node mergeNodes(const Node &left, const Node &right) {
    Node result;
    result.ms = result.mp = result.mss = result.tsum = 0;
    
    result.mp = max({left.mp, left.tsum + right.mp, left.tsum + right.tsum});
    result.mss = max({right.mss, right.tsum + left.mss, left.tsum + right.tsum});
    result.tsum = left.tsum + right.tsum;
    
    result.ms = max({result.mp, result.mss, result.tsum, left.ms, right.ms, left.mss + right.mp});

    return result;
}

Node max_subarray(int left, int right, int ar[]) {
    if (left == right) return getNode(ar[left]);

    int mid = (left + right) >> 1;
    
    Node leftNode = max_subarray(left, mid, ar);
    Node rightNode = max_subarray(mid + 1, right, ar);
    
    return mergeNodes(leftNode, rightNode);
}

int main() {

    freopen("test_cases_Q2.txt","r",stdin);
    freopen("output_Q2.txt","w",stdout);

    cin.tie(NULL);
	int tt;
	cin >> tt; 
	while(tt--)
	{
       int n; cin>>n; int ar[n];
       rep(i,0,n){cin>>ar[i];}
       Node result = max_subarray(0, n - 1, ar);
       cout << "Answer is " << result.ms << "\n";
    }
    return 0;
}
