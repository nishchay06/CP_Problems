#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<int> findNumberSequence(string direction) {
    int n = size(direction);
    vector<int> ans(n);
    int l = 0, r = n-1;
    int i = 0;
    while(i < n) {
        if(direction[i] == 'L') {
            ans[r] = i+1;
            r--;
        } 
        else {
            ans[l] = i+1;
            l++;
        }
        i++;
    }
    return ans;
}

void solve() {
    string dir;
    cin >> dir;
    vector<int> ans = findNumberSequence(dir);
    for(int i = 0; i < ans.size(); i++) {
        cout<<ans[i];
    }
    cout<<endl;
}

int main(){
    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
}