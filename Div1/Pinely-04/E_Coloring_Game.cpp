#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define vi vector<int>
#define pii pair<int, int>
#define f first
#define s second

void is_bipartite(int u, vector<vi> &adj, vi &color, bool &isBipartite){
    for(int v: adj[u]){
        if(color[v] == -1){
            color[v] = color[u] ^ 1;
            is_bipartite(v, adj, color, isBipartite);
        } else {
            if(color[v] != (color[u] ^ 1)){
                isBipartite = false;
                return;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<vi> adj(n+1);
        for(int i = 0; i < m; i++){
            int u, v;
            cin >> u >> v;
            u; v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vi color(n+1, -1);
        color[1] = 1;
        bool isBipartite = true;
        is_bipartite(1, adj, color, isBipartite);
        if(!isBipartite){
            cout << "Alice" << endl;
            int pos, c;
            for(int i = 0; i < n; i++){
                cout << 1 << " " << 2 << endl;
                cin >> pos >> c;
            }
        } else {
            cout << "Bob" << endl;
            int c, c1, c2, pos;

            vi part1, part2;
            for(int i = 1; i <= n; i++){
                if(color[i]) part1.push_back(i);
                else part2.push_back(i);
            }
            for(int i = 0; i < n; i++){
                cin >> c1 >> c2;
                if((c1 == 1 || c2 == 1) && part1.size()){
                    c = 1;
                    pos = part1.back();
                    part1.pop_back();
                } else if((c1 == 2 || c2 == 2) && part2.size()){
                    c = 2;
                    pos = part2.back();
                    part2.pop_back();
                } else if(part1.size() == 0){
                    c = (c1 == 1 ? c2 : c1);
                    pos = part2.back();
                    part2.pop_back();
                } else {
                    c = (c1 == 2 ? c2 : c1);
                    pos = part1.back();
                    part1.pop_back();
                }
                cout << pos << " " << c<< endl;
            }
        }
    }
    return 0;
}