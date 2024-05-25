#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n; cin>>n;
        vector<vector<int>> A;
        vector<int> a(n);
        for(int i = 0;i<n;++i) cin>>a[i];
        for(int i=0;i<n-1;++i){
            for(int j = i+1; j<n;++j){
                if(a[j] < a[i]) swap(a[i],a[j]);
            }
            A.push_back(a);
        }
        for(int i = A.size()-1; i>=0;i--){
            cout<<"Buoc "<<i+1<<": ";
            for(int j = 0;j<n;++j){
                cout<<A[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}