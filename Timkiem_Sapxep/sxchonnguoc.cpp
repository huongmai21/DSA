#include<bits/stdc++.h>

using namespace std;

int main(){
    int n; cin>>n;
    vector<vector<int>> A;
    vector<int> a(n);
    for(int i = 0;i<n;++i) cin>>a[i];
    for(int i=0;i<n-1;++i){
        int min_index = i;
        for(int j = i+1; j<n;++j){
            if(a[j] < a[min_index]){
                min_index = j;
            }
        }
        swap(a[i],a[min_index]);
        A.push_back(a);
    }
    for(int i = A.size()-1; i>=0;i--){
        cout<<"Buoc "<<i+1<<": ";
        for(int j = 0;j<n;++j){
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}