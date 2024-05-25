#include<bits/stdc++.h>

using namespace std;

int dp[1005][10005];
int n,k;

int mod = 1e9+7;

void tgPascal(){
    dp[1][0] = 1;
    dp[1][1] =1 ;
    for(int i=2;i<=n;++i){
        for(int j=0;j<=i;++j){
            if(j == 0 || j == i) dp[i][j] = 1;
            else dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            dp[i][j] %= mod;
        }
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n>>k;
        tgPascal();
        cout<<dp[n][k]<<endl;
    }
    return 0;
}