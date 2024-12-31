// #include<bits/stdc++.h>
#include </Users/nishchay/Desktop/abc.h>
using namespace std;

void solve() {
    int n,m;
    cin >> n >> m;
    vector<vector<pair<int,int>>> adjl(n);
    for(int i = 0; i < m; i++) {
        int u,v,w;
        cin >> u >> v >> w;
        adjl[u].push_back({v,w});
        adjl[v].push_back({u,w});
    }

    vector<int> vis(n);
    priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> q;
    q.push({0,0,-1});

    int mst = 0;
    vector<vector<int>> edgemst; 

    while(size(q)) {
        auto cr = q.top();
        q.pop();

        int crwt = cr[0], crnode = cr[1], crpar = cr[2];

        if(vis[crnode]) continue;
        vis[crnode] = 1;
        mst += crwt;
        if(crpar != -1) edgemst.push_back({crnode,crpar});

        for(auto& it : adjl[crnode]) {
            int nxtnode = it.first, edgewt = it.second;
            q.push({edgewt,nxtnode,crnode});
        }
    }

    cout<<"The MST edges are : "<<endl;
    for(auto &it : edgemst) {
        cout<<it[0]<<" "<<it[1]<<endl;
    }
    cout<<"The MST weight is "<<mst<<endl;

}

int main() {
    int t = 1;
    while(t--) {
        solve();
    }
    return 0;
}