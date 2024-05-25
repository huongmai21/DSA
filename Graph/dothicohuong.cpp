//Code tu anh 28tech
#include<bits/stdc++.h>

using namespace std;
int n, m,  a[101][101], e[101] ;
bool visited[101];
vector<int> ke[101];
vector<pair<int,int>> dscanh;
int ID[101], dem = 0;

void nhap(){ //ds ke
    cin>>n>>m;
    while(m--){
        int x, y;
        cin>>x>>y;
        ke[x].push_back(y);
        ke[y].push_back(x);
    }
    for(int i=1; i<=n;++i){
        sort(ke[i].begin(),ke[i].end());
    }
    memset(visited, false, sizeof(visited));
    memset(e, 0, sizeof(e));
}

//Chu trinh tren do thi co huong
// sd DFS chuan voi 3 mau :
// chua tham (mau trang :0), chua chay xong (mau xam :1), xong (mau den: 2)
int color[1005];
bool DFS(int u){
    color[u] = 1;
    for(int v : ke[u]){
        if(color[v] == 0){
            if(DFS(v))
            return true;
        }
        else if(color[v] == 1){
            return true;
        }
    }
    color[u] = 2;
    return false;
}

//voi thuat toan BFS
int degree[1005];
bool Kahn(){
    for(int i = 1; i <= n; i++){
        for(int x : ke[i]){
            degree[x]++; // ban bac vao
        }
    }
    queue<int> q;
    for(int i = 1; i <= n; i++){
        if(degree[i] == 0){
            q.push(i);
        }
    }

    int cnt = 0;
    while(!q.empty()){
        int u = q.front(); q.pop();
        ++cnt;
        for(int v : ke[u]){
            --degree[v];
            if(degree[v] == 0){
                q.push(v);
            }
        }
    }
    if(cnt != n) return true;
    else return false;
}

int main(){
    return 0;
}