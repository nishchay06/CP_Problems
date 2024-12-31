#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    int n;
    cin >> n;
    vector<int> c(n);
    for(int i = 0; i < n; i++) cin >> c[i];
    int m;
    cin >> m;
    vector<vector<vector<int>>> adjl(n);
    for(int i = 0; i < m; i++) {
        int u,v,l;
        cin >> u >> v >> l;
        adjl[u].push_back({v,l});
        adjl[v].push_back({u,l});
    }
    int s,d;
    cin >> s >> d;
    
}

int main(){
    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
}