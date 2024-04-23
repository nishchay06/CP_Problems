#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void dfs1(int cr, vector<vector<int>> &adjl, vector<int> &vis, vector<int> &order) {
    vis[cr] = 1;
    for(auto &ch : adjl[cr]) {
        if(!vis[ch]) {
            dfs1(ch,adjl,vis,order);
        }
    }
    order.push_back(cr);
}

void dfs2(int cr, vector<vector<int>> &adjl, vector<int> &vis, vector<int> &cr_scc) {
    vis[cr] = 1;
    cr_scc.push_back(cr);
    for(auto &ch : adjl[cr]) {
        if(!vis[ch]) {
            dfs2(ch,adjl,vis,cr_scc);
        }
    }
}

void solve() {
    int n,m;
    cin >> n >> m;
    vector<vector<int>> adjl(n);
    for(int i = 0; i < m; i++) {
        int u,v;
        cin >> u >> v;
        adjl[u].push_back(v);
    } 

    // Step 1
    vector<int> vis(n);
    vector<int> order;

    for(int i = 0; i < n; i++) {
        if(!vis[i]) dfs1(i,adjl,vis,order);
    }

    reverse(begin(order),end(order));

    // Step 2
    vector<vector<int>> adjl_rev(n);
    for(int i = 0; i < n; i++) {
        for(auto &ch : adjl[i]) {
            adjl_rev[ch].push_back(i);
        }
    }

    // Step 3
    vis.assign(n,0);
    vector<vector<int>> scc;
    for(int i = 0; i < n; i++) {
        int cr = order[i];
        if(!vis[cr]) {
            vector<int> cr_scc;
            dfs2(cr,adjl_rev,vis,cr_scc);
            scc.push_back(cr_scc);
        }
    }
    
    cout<<"The number of SCC are : "<<size(scc)<<endl;
    for(auto &cr_scc : scc) {
        for(auto &ele : cr_scc) {
            cout<<ele<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
}

/*
    Kosaraju's Algo
    1. Sort the edges according to finishing time
    2. Reverse all the edges
    3. Perform the DFS
*/