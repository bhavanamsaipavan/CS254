#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef long double ld;
using namespace std;

typedef vector<vector<int>> Mx; // Matrix
typedef vector<int> vi; 

Mx add(const Mx &A, const Mx &B){
    int n = A.size(), m = A[0].size() ;
    Mx result(n, vi(m));
    rep(i,0,n){
        rep(j,0,m){
            result[i][j] = A[i][j]+B[i][j]; 
        }
    }
    return result;
}
Mx subtract(const Mx &A, const Mx &B){
    int n = A.size(), m = A[0].size() ;
    Mx result(n, vi(m));
    rep(i,0,n){
        rep(j,0,m){
            result[i][j] = A[i][j]-B[i][j]; 
        }
    }
    return result;
}

// T(N) = 8T(N/2) + O(N2)  ==> T(N) same as the naive method and taking extra space
Mx MM(const Mx &A,const Mx &B)
{
    int n1 = A.size();
    int n2 = B.size();

    if (n1 != n2)
    {
        cerr << "\nError: enter vaild Matrices\n ";
        return {};
    }

    Mx c(n1, vi(n1,0));

    if (n1 == 1) { c[0][0] = A[0][0] * B[0][0]; return c;} // base case

    int v = log2(n1);
    if (pow(2,v) != n1 ) { n1 = pow(2,v+1); } // padding for matrix of size other than 2 powers


    int si = n1 / 2;

    Mx a00(si, vi(si,0)), a01(si, vi(si,0)), a10(si, vi(si,0)), a11(si, vi(si,0));
    Mx b00(si, vi(si,0)), b01(si, vi(si,0)), b10(si, vi(si,0)), b11(si, vi(si,0));

    rep(i, 0, si)
    {
        rep(j, 0, si)
        {
            a00[i][j] = A[i][j];
            b00[i][j] = B[i][j];
            if(j + si < n2) {
               a01[i][j] = A[i][j + si];
               b01[i][j] = B[i][j + si];
            }
            if(i + si < n2) {
               a10[i][j] = A[si + i][j];
               b10[i][j] = B[si + i][j];
            }
            if(j + si < n2 && i + si < n2){
               a11[i][j] = A[i + si][j + si];
               b11[i][j] = B[i + si][j + si];
            }
        }
    }

    Mx c_00 = add(MM(a00, b00),MM(a01, b10));
    Mx c_01 = add(MM(a00, b01),MM(a01, b11));
    Mx c_10 = add(MM(a10, b00),MM(a11, b10));
    Mx c_11 = add(MM(a10, b01),MM(a11, b11));

    rep(i, 0, si)
    {
        rep(j, 0, si)
        {
            c[i][j] = c_00[i][j];
            if(j + si < n2) {
               c[i][j + si] = c_01[i][j];
            }
            if(i + si < n2) {
               c[si + i][j] = c_10[i][j];
            }
            if(j + si < n2 && i + si < n2){
               c[i + si][j + si] = c_11[i][j];
            }
        }
    }

    c_00.clear(); c_01.clear(); c_10.clear(); c_11.clear();
    a00.clear(); a01.clear(); a10.clear(); a11.clear(); b00.clear(); b01.clear(); b10.clear(); b11.clear();
    
    return c;
}

// T(N) = 7T(N/2) + O(N2) ==> better than naive but not practical
Mx strassen(const Mx &A,const Mx &B)
{
    int n1 = A.size();
    int n2 = B.size();

    if (n1 != n2)
    {
        cerr << "\nError: enter vaild Matrices\n ";
        return {};
    }

    Mx c(n1, vi(n1,0));

    if (n1 == 1) { c[0][0] = A[0][0] * B[0][0]; return c;} // base case

    int v = log2(n1);
    if (pow(2,v) != n1 ) { n1 = pow(2,v+1); } // padding for matrix of size other than 2 powers


    int si = n1 / 2;

    Mx a00(si, vi(si,0)), a01(si, vi(si,0)), a10(si, vi(si,0)), a11(si, vi(si,0));
    Mx b00(si, vi(si,0)), b01(si, vi(si,0)), b10(si, vi(si,0)), b11(si, vi(si,0));

    rep(i, 0, si)
    {
        rep(j, 0, si)
        {
            a00[i][j] = A[i][j];
            b00[i][j] = B[i][j];
            if(j + si < n2) {
               a01[i][j] = A[i][j + si];
               b01[i][j] = B[i][j + si];
            }
            if(i + si < n2) {
               a10[i][j] = A[si + i][j];
               b10[i][j] = B[si + i][j];
            }
            if(j + si < n2 && i + si < n2){
               a11[i][j] = A[i + si][j + si];
               b11[i][j] = B[i + si][j + si];
            }
        }
    }

    Mx p1 = strassen(a00, subtract(b01,b11));
    Mx p2 = strassen(add(a00,a01), b11);
    Mx p3 = strassen(add(a10,a11), b00);
    Mx p4 = strassen(a11, subtract(b10,b00));
    Mx p5 = strassen(add(a00,a11), add(b00,b11));
    Mx p6 = strassen(subtract(a01,a11), add(b10,b11));
    Mx p7 = strassen(subtract(a00,a10), add(b00,b01));

    Mx c_00 = subtract(add(add(p5,p4),p6),p6);
    Mx c_01 = add(p1,p2);
    Mx c_10 = add(p3,p4);
    Mx c_11 = subtract(add(p1,p5),add(p3,p7));

    rep(i, 0, si)
    {
        rep(j, 0, si)
        {
            c[i][j] = c_00[i][j];
            if(j + si < n2) {
               c[i][j + si] = c_01[i][j];
            }
            if(i + si < n2) {
               c[si + i][j] = c_10[i][j];
            }
            if(j + si < n2 && i + si < n2){
               c[i + si][j + si] = c_11[i][j];
            }
        }
    }
    p1.clear(); p2.clear(); p3.clear(); p4.clear(); p5.clear(); p6.clear(); p7.clear(); 
    c_00.clear(); c_01.clear(); c_10.clear(); c_11.clear();
    a00.clear(); a01.clear(); a10.clear(); a11.clear(); b00.clear(); b01.clear(); b10.clear(); b11.clear();
    
    return c;
}


int main() {

    freopen("test_cases_Q1.txt","r",stdin);
    freopen("output_Q1.txt","w",stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	int t;
	cin >> t; 
	while(t--)
	    {
        int n; cin>>n;
        Mx A(n,vi(n)), B(n,vi(n));
        rep(i,0,n){
            rep(j,0,n){
                cin>>A[i][j];
            }
        }
        rep(i,0,n){
            rep(j,0,n){
                cin>>B[i][j];
            }
        }
        Mx C =strassen(A,B);
        rep(i,0,n){
            rep(j,0,n){
                cout<<C[i][j]<<" ";
            }cout<<"\n";
        }   cout<<"\n";
    }
}    