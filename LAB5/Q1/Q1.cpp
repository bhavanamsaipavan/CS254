#include <bits/stdc++.h>
using namespace std;

bool valid(int i, int j, int n, int m){
    return i >= 0 && j >= 0 && i < n && j < m;
}

int bfs(vector<vector<int>>& matrix, vector<vector<bool>> &visited, int i , int j){

    queue<pair<int, int>> q;
    int n = matrix.size();
    int m = matrix[0].size();
    int ans = 1;
    q.emplace(i, j);
    visited[i][j] = true;

    while(!q.empty()){

        auto node = q.front();
        q.pop();

        int a = node.first, b = node.second;

        for(int i = -1; i <= 1; i++){
            for(int j = -1; j <= 1; j++){
                int new_x = a + i;
                int new_y = b + j;

                if(valid(new_x, new_y, n, m)){
                    if(!visited[new_x][new_y] && matrix[new_x][new_y]){
                        q.emplace(new_x, new_y);
                        visited[new_x][new_y] = true;
                        ans++;
                    }
                }
            }
        }
    }

    return ans;
}

int largestRegion(vector<vector<int>>& matrix){

    int ans = 0;
    int n = matrix.size();
    int m = matrix[0].size();

    if(n == 0 || m == 0)return ans;

    vector<vector<bool>> visited(n, vector<bool>(m, false));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){

            if(matrix[i][j]){
                ans = max(ans, bfs(matrix, visited, i, j));
            }
        }
    }

    return ans;
}

int main(){

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t;
    cin >> t;

    while(t--){

        int n, m; 
        cin >> n >> m;

        if(n == 0 || m == 0){
            cout << "Largest region of the given matrix is " << 0 << endl;
            continue;
        }

        vector<vector<int>> matrix(n, vector<int>(m));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> matrix[i][j];
            }
        }

        cout << "Largest region of the given matrix is " << largestRegion(matrix) << endl;
    }
    
return 0;

}