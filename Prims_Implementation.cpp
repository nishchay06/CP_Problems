#include </Users/nishchay/Desktop/abc.h>
using namespace std;

int main(){
    cout << "Given is a undirected weighted graph. Implement Prims Algo to find the MST edges.\n";
    cout << "(Please Note: The edges are 1-indexed)\n";
    int n, m;
    cout << "Enter the number of nodes: ";
    cin >> n;
    vector<vector<int>> adjl[n];
    cout << "Enter the number of edges: ";
    cin >> m;
    cout << "Enter the edges: ";
    for(int i = 0; i < m; i++) {
        int u,v,w;
        cin >> u >> v >> w;
        // convert to 0 indexed
        u -= 1, v -= 1;
        adjl[u].push_back({v,w});
        adjl[v].push_back({u,w});
    }

    // variable for weight of MST
    int mstWt = 0;

    // construct a visited array
    vector<int> vis(n);
    
    priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> q;
    
    // let the parent be node 0
    // the format for minheap will be {edgewt, crnode, parentnode}
    q.push({0,0,-1});

    while(!q.empty()) {
        auto cr = q.top();
        q.pop();
        int crwt = cr[0], crnode = cr[1], parnode = cr[2];
        // check if visited
        if(vis[crnode] == 1) continue;
        vis[crnode] = 1;
        // this edge/node is part of mst
        if(parnode != -1) cout << parnode+1 << " -> " << crnode+1 << " with wt " << crwt << endl;
        mstWt += crwt;

        // add all edges outgoing from crnode to minheap
        for(auto& it : adjl[crnode]) {
            int nxtnode = it[0], edgewt = it[1];
            q.push({edgewt,nxtnode,crnode});
        }
    }

    cout << "The weight of MST for this graph is " << mstWt;

    return 0;
}