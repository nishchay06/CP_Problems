#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

class DSU {
    vector<int> par, rank;
    public:
    DSU(int n) {
        par.assign(n,-1);
        for(int i = 0; i < n; i++) {
            par[i] = i;
        }
        rank.assign(n,1);
    }

    int find(int a) {
        if(par[a] != a) par[a] = find(par[a]);
        return par[a];
    }

    void merge(int a, int b) {
        a = find(a);
        b = find(b);

        if(a != b) {
            if(rank[a] < rank[b]) {
                swap(a,b);
            }
            par[b] = a;
            rank[a] += rank[b];
        }
    }

    bool inSame(int a, int b) {
        return find(a) == find(b);
    }
};

void solve() {
    int n,m;
    cin >> n >> m;
    vector<vector<int>> edges;
    // O(E)
    for(int i = 0; i < m; i++) {
        int u,v,w;
        cin >> u >> v >> w;
        edges.push_back({w,u,v});
    }

    int mst = 0;
    vector<vector<int>> edgemst; 


    DSU dsu(n);
    // O(E logE)
    sort(begin(edges),end(edges));

    for(auto &edge : edges) {
        int wt = edge[0], u = edge[1], v = edge[2];
        if(dsu.inSame(u,v)) continue;
        dsu.merge(u,v);
        mst += wt;
        edgemst.push_back({u,v});
    }

    cout<<"The MST edges are : "<<endl;
    for(auto &it : edgemst) {
        cout<<it[0]<<" "<<it[1]<<endl;
    }
    cout<<"The MST weight is "<<mst<<endl;

}

int main(){
    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
}