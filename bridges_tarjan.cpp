#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void dfs(int i, int par, vector<vector<int>> &adjl, vector<int> &time, vector<int> &low, int &t, vector<vector<int>> &bridge, vector<int> &vis) {

    // initialize time and low
    time[i] = low[i] = t++; 
    vis[i] = 1;

    for(auto &ch : adjl[i]) {
        if(ch != par) {

            // dfs of unvisitied node
            if(!vis[ch]) {
                dfs(ch,i,adjl,time,low,t,bridge,vis);
            }

            // to check edge of i -> ch
            if(time[i] < low[ch]) {
                // this is a bridge
                bridge.push_back({i,ch});
            }

            // update current low
            low[i] = min(low[i],low[ch]);
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adjl(n);
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adjl[u].push_back(v);
        adjl[v].push_back(u);
    }

    vector<int> time(n,-1), low(n,-1), vis(n);
    vector<vector<int>> bridge;
    
    int t = 1;
    for(int i = 0; i < n; i++) {
        if(!vis[i]) {
            dfs(i,-1,adjl,time,low,t,bridge,vis);
        }
    }

    cout<<"These are the "<<size(bridge)<<" bridge edges.\n";
    for(auto &edge: bridge) {
        cout<<edge[0]+1<<" -> "<<edge[1]+1<<endl;
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

    Tarjan's Algo
    1. Perform DFS on nodes
    2. Set time and low of all nodes to starting time
    3. DFS of unvisited child
    4. Check if edge is bridge => iff time[i] less than low[ch]
    5. Update low[i]
*/