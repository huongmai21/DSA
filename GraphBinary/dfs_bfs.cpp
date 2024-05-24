//code tu anh 28tech
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

//DFS ds ke
void DFS1(int u){
    //cout<<u<<" ";
    visited[u] = true;
    for(int v : ke[u]){
        if(!visited[v]){
            e[v] = u;
            DFS1(v);
        }
    }
}

//DFS ma tran ke
void DFS2(int u){
    cout<<u<<" ";
    visited[u] = true;
    for(int i =1;i<=n;++i){
        if(a[u][i] == 1){
            if(!visited[i]){
                e[i] = u;
                DFS2(i);
            }
        }
    }
}

//DFS ds canh
void DFS3(int u){
    cout<<u<<" ";
    visited[u] = true;
    for(auto it : dscanh){
        if(it.first == u){
            if(!visited[it.second]){
                DFS3(it.second);
            }
        }
        if(it.second == u){
            if(!visited[it.first]){
                DFS3(it.first);
            }
        }
    }
}

//BFS ds ke
void BFS(int u){
    queue<int> q;
    q.push(u);
    visited[u] = true;
    while(!q.empty()){
        int x = q.front(); q.pop();
        cout<<x<< " ";
        for(int y : ke[x]){
            if(!visited[y]){
                q.push(y);
                visited[y] = true;
                e[y] = x;
            }
        }
    }
}

//tim so tplt
int tplt(){
    int count = 0;
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            ++count;
            DFS1(i); // BFS(i);
        }
    }
    return count;
}

// Tim duong di giua 2 dinh tren do thi
// dung mang ID de luu cac dinh thuoc thanh phan lien thong thu may 
// cach nay tranh TLE
void BFS1(int u){
    queue<int> q;
    q.push(u);
    visited[u] = true;
    while(!q.empty()){
        int x = q.front(); q.pop();
        ID[x] = dem;
        cout<<x<< " ";
        for(int y : ke[x]){
            if(!visited[y]){
                q.push(y);
                visited[y] = true;
            }
        }
    }
}

int timDuong(int u, int v){ // kiem tra co duong di hay ko
    for(int i=1;i<=n;++i){
        if(!visited[i]){
            ++dem;
            BFS(i);
        }
    }

    int x, y;
    cin>>x>>y;
    if(ID[x] == ID[y]) return 1;
    else return 0;
}

//Tim duong di giua 2 dinh , liet ke duong di
int s, t;
void timDuong2(){
    cin>>s>>t;
    DFS1(s);
    if(!visited[t]){
        cout<<"-1\n";
    }
    else{
        vector<int> res;
        while(t != s){
            res.push_back(t);
            t = e[t];
        }
        res.push_back(s);
        reverse(res.begin(),res.end());
        for(int x : res){
            cout<<x<<"->";
        }
    }
}

// dinh tru , canh cau
void dinhTru(){
    int k = tplt(); // so tplt ban dau
    for(int i=1;i<=n;++i){
        memset(visited,false,sizeof(visited));
        visited[i] = true; // loai bo i khoi do thi
        if(k < tplt()){
            cout<<i<<" ";
        }
    }
}

//Canh cau : cach 1
set<int> ke2[101];
void nhap2(){ // tu ds ke , luu ds canh
    cin>>n>>m;
    while(m--){
        int x, y;
        cin>>x>>y;
        dscanh.push_back({x,y});
        ke2[x].insert(y);
        ke2[y].insert(x);
    }
}

void canhCau(){ 
    int k = tplt();
    int cnt = 0;
    for(auto it : dscanh){
        int x = it.first, y = it.second;
        ke2[x].erase(y); // xoa canh (x,y)
        ke2[y].erase(x);
        memset(visited,false,sizeof(visited));
        if(k <tplt()){
            ++cnt;
        }
        ke2[x].insert(y);
        ke2[y].insert(x);
    }
}

//canh cau : cach 2
void DFS(int u, int s,int t){
    //cout<<u<<" ";
    visited[u] = true;
    for(int v : ke[u]){
        //Neu xet phai canh muon loai bo thi khong xet
        if((u == s && v == t) || (u == t && v == s)){
            continue;
        }
        if(!visited[v]){
            DFS(v,s,t);
        }
    }
}

int tplt(int s, int t){
    int cnt = 0;
    for(int i=1;i<=n;++i){
        if(!visited[i]){
            ++cnt;
            DFS(i,s,t);
        }
    }
    return cnt;
}

void canhcau(){
    int k = tplt(0,0);
    for(auto it : dscanh){
        int x = it.first, y = it.second;
        memset(visited,false,sizeof(visited));
        if(k < tplt(x,y)){
            cout<<x<<" "<<y<<" ";
        }
    }
}

void testcase(){
    cin>>n>>m;
    for(int i =1;i<=n;++i) ke2[i].clear();
    dscanh.clear();
    memset(visited,false,sizeof(visited));
    while(m--){
        int x, y;
        cin>>x>>y;
        dscanh.push_back({min(x,y), max(x,y)});
        ke2[x].insert(y);
        ke2[y].insert(x);
    }
    canhcau();
    cout<<endl;
}

//Chu trinh tren do thi vo huong
bool DFS(int u){
    visited[u] = true;
    for(int v :  ke[u]){
        if(!visited[v]){
            e[v] = u; 
            if(DFS(v)) return true;
        }
        else if(v != e[u]){
            return true;
        }
    }
    return false;
}

bool BFS2(int u){
    queue<int> q;
    q.push(u);
    visited[u] = true;
    while(!q.empty()){
        int x = q.front(); q.pop();
        for(int y : ke[x]){
            if(!visited[y]){
                q.push(y);
                visited[y] = true;
                e[y] = x;
            }
            else if(y != e[x]) return true;
        }
    }
    return false;
}

int main(){
    nhap();
    return 0;
}