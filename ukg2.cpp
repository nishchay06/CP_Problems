#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int findMaximumGreatness(vector<int>& arr) {
    int n = size(arr);
    vector<int> desc = arr;
    sort(rbegin(desc),rend(desc));
    priority_queue<int> pq;
    for(int i = 0; i < n; i++) {
        pq.push(arr[i]);
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
        int cr = pq.top();
        if(cr > desc[i]) {
            pq.pop();
            ans++;
        }
    }
    return ans;
}

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout<<findMaximumGreatness(arr)<<endl;
}

int main(){
    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
}