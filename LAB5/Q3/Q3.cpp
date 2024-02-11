#include <bits/stdc++.h>
using namespace std;

void compliment_graph(vector<vector<int>> &adj){
    int n = adj.size();

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            adj[i][j] = !adj[i][j];
        }
    }
}

bool check_2_clique(vector<vector<int>> &adj){
    int n = adj.size();
    vector<vector<int>> adj_list(n);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(adj[i][j]){
                adj_list[i].emplace_back(j);
            }
        }
    }

    vector<int> color(n, -1);

    color[0] = 1;

    queue<int> q;
    q.push(0);

    while(!q.empty()){
        int node = q.front();
        q.pop();

        int curr_color = color[node];

        for(int &i: adj_list[node]){
            if(color[i] == curr_color){
                return false;
            }

            if(color[i] == -1){
                color[i] = !curr_color;
                q.push(i);
            }
        }
    }

    for(int &i: color){
        if(i == -1)return false;
    }

    return true;
    
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t;
    cin >> t;

    while(t--){
        int n;

        cin >> n;

        vector<vector<int>> matrix(n, vector<int>(n));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n ;j++){
                cin >> matrix[i][j];

                matrix[i][j] != matrix[i][j];
            }
        }

        // compliment_graph(matrix);

        if(check_2_clique(matrix)){
            cout << "The given graph can be divided into 2 cliques" << endl;
        }

        else{
            cout << "The given graph cannot be divided into 2 cliques" << endl;
        }
    }
 
return 0;
}