#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    int t;
    cin>>t;
    while(t--){
        ll s, t; cin >> s >> t;
		queue<pair<ll, ll>> X;
		set<int> S;
		S.insert( s);
		X.push({ s,0 });
		while (X.size()) {
			pair<ll, ll> x = X.front();
			X.pop();
			if (x.first-1 == t||x.first*2==t) {
				cout << x.second+1 << endl;
				break;
			}
			if (S.count( x.first - 1) == 0&&x.first-1>0) {
				X.push({ x.first - 1,x.second + 1 });
				S.insert(x.first - 1);
			}
			if (S.count( x.first * 2) == 0 && x.first < t) {
				X.push({ x.first * 2,x.second + 1 });
				S.insert( x.first * 2);
			}
			
		}
        
    }
    return 0;
}