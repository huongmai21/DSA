#include<bits/stdc++.h>

using namespace std;

int n, m, a[101][101];
vector<int> ke[101];

//ds canh sang matran ke
void chuyen1(){
    cin>>n>>m;
    memset(a,0,sizeof(a));
    while(m--){
        int x, y;
        cin>>x>>y;
        a[x][y] = 1;
        a[y][x] = 1; // vo huong
    }
    for(int i=1;i<=n;++i){
        for(int j =0;j<n;++j){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}

//ds canh sang ds ke
void chuyen2(){
    cin>>n>>m;
    while(m--){
        int x, y;
        cin>>x>>y;
        ke[x].push_back(y);
        ke[y].push_back(x); // vo huong
    }
    for(int i=1;i<=n;++i){
        cout<<i<<":";
        sort(ke[i].begin(),ke[i].end());
        for(int j =0;j<ke[i].size();++j){ // for(int x : ke[i]) cout<<x<<" ";
            cout<<ke[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    chuyen1();
    //chuyen2();
}