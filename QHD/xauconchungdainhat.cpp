#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        string s1, s2;
        cin>>s1>>s2;
        int dp[s1.size()+1][s2.size()+1];
        for(int i=0;i<=s2.size();++i) dp[0][i] = 0;
        for(int i=0;i<=s1.size();++i) dp[i][0] = 0;
        for(int i=0;i<s1.size();++i){
            for(int j=0;j<s2.size();++j){
                if(s1[i] == s2[j]) dp[i+1][j+1] = dp[i][j] +1;
                else dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
            }
        }
        cout<<dp[s1.size()][s2.size()]<<endl;
    }
    return 0;
}