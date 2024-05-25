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
        for (int i = 0; i < n; ++i) {
        bool check = false;
        for(int j=0;j<n-i-1;++j){
            if(a[j] > a[j+1]){
                swap(a[j],a[j+1]);
                check = true;
            }
        }
        if(!check) break;
        A.push_back(a); 
        }

        for (int i = A.size() - 1; i >= 0; --i) {
            cout << "Buoc " + to_string(i+1) + ": ";
            for (int j = 0; j < A[i].size(); ++j) {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}