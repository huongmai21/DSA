#include<bits/stdc++.h>

using namespace std;

int n, m;
bool visited[1001];
vector<int> ke[1001];
bool ok;

void DFS(int u, int count){
    if(count == n) ok=true;
    visited[u] = true;
    for(auto x : ke[u]){
        if(!visited[x]) DFS(x, count +1);
    }
    visited[u] = false;
}

int Hamilton(){
    for(int i=1;i<=n;++i){
        memset(visited,false,sizeof(visited));
        ok = false;
        DFS(i,1);
        if(ok) return 1;
    }
    return 0;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        for(int i=1; i<=n;++i){
            ke[i].clear();
            visited[i] = false;
        }
        cin>>n>>m;
        while(m--){
            int x, y;
            cin>>x>>y;
            ke[x].push_back(y);
            ke[y].push_back(x);
        }
        cout<<Hamilton()<<endl;
    }    
}