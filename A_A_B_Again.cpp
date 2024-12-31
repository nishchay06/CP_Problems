#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    int n;
    cin >> n;
    int ans = 0;
    while(n){
        ans += n%10;
        n /= 10;
    }
    cout<<ans<<endl;
}

int main(){
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
}