#include<bits/stdc++.h>

using namespace std;

int main(){
    int n; cin>>n;
    vector<vector<int>> A;
    vector<int> a(n);
    for(int i = 0;i<n;++i) cin>>a[i];
    for (int i = 0; i < n; ++i) {
        int j = i;
        while (j > 0 && a[j] < a[j - 1]) {
            swap(a[j], a[j - 1]);
            j--;
        }
        vector<int> temp(a.begin(), a.begin() + i + 1);
        A.push_back(temp);
    }

    for (int i = A.size() - 1; i >= 0; --i) {
        cout << "Buoc " + to_string(i) + ": ";
        for (int j = 0; j < A[i].size(); ++j) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}