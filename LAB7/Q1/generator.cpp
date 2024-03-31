#include <bits/stdc++.h>

using namespace std;

int main(){

    freopen("input.txt", "w", stdout);

    int t = rand();

    while(t--){
        int n = rand()%100 + 1;
        int W = rand()%100 + 1;

        cout << n << ' ' << W << endl;

        for(int i = 0; i < n; i++){
            cout << rand()%100 + 1 << " ";
        }

        cout << endl;

        for(int i = 0; i < n; i++){
            cout << rand()%100 + 1 << " ";
        }

        cout << endl;

    }
}