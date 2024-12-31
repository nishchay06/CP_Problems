#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll f(int n, vector<vector<int>>& edges) {
    vector<vector<int>> adjl(n);
    for(auto & it : edges) {
        int u = it[0], v = it[1], w = it[2];
        adjl[u].push_back({v,w});
    }
    if(n == 1) return 0;
    vector<ll> ans(n, 1e9), mx(n), total(n, 1e9);
    queue<ll> q;
    q.push(1);
    while(q.size()) {
        auto cr = q.front();
        q.pop();
        for(auto & it : adjl[n]) {
            int nx = it[0], crwt = it[1];
            if(total[nx] > total[cr] + crwt) {
                total[nx] = total[cr] + crwt;
                mx[nx] = max(mx[cr],crwt);
            }
            else {
                
            }
            total[nx] = min(total[nx],total[cr]+crwt);
            mx[nx] = max(max(mx[cr],crwt),mx[nx]);
            ll res = 0;
            if(crwt > mx[cr]) {
                res = (crwt/2) + total[cr];
            } 
            else res = ans[cr] + crwt;
            ans[nx] = min(ans[nx],res)
        }
    }
    return ans[n];
}

void solve() {
    
}

int main(){
    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
}