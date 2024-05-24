#include<bits/stdc++.h>

using namespace std;

int n, m;
int color[1001];
set<int> ke[1001];

bool BFS(int u){
    queue<int> Q;
    Q.push(u);
    color[u] = 1;
    while(Q.size()){
        int x = Q.front(); Q.pop();
        for(int v : ke[x]){
            if(color[v] == 0){
                color[v] = 3 - color[x];
                Q.push(v);
            }
            else if(color[v] == color[x]) return false;
        }
    }
    return true;
}

string Load(){
    for(int i=1;i<=n;++i){
        if(color[i] == 0){
            if(!BFS(i)) return "NO\n";
        }
    }
    return "YES\n";
}

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n>>m;
        for(int i=1;i<=n;++i){
            ke[i].clear();
            color[i] = 0;
        }
        while(m--){
            int a, b;
            cin>>a>>b;
            ke[a].insert(b);
            ke[b].insert(a);
        }
        cout<<Load();
    }
    return 0;
}