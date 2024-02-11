#include <bits/stdc++.h>

using namespace std;

int main(){

    freopen("input.txt", "w", stdout);

    int t = rand();

    cout << t << endl;

    while(t--){

        int n = rand()%100, m = rand()%100;

        cout << n << ' ' << m  << endl;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int x = rand();

                cout << x%2 << ' ';
            }

            cout << endl;
        }
    }

    return 0;
}