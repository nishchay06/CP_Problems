// #include </Users/nishchay/Desktop/abc.h>
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve() {
    int n, m; cin >> n >> m;
    
    vector <int> a(n);
    vector <int> b(m);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;
    
    vector <int> c(n, 0);
    sort(b.begin(), b.end());
    for (int i = 1; i < n; i++){
        // find number of people in range a[0] + 1...a[i] 
        if (a[0] >= a[i]) continue;
        int num = upper_bound(b.begin(), b.end(), a[i]) - upper_bound(b.begin(), b.end(), a[0]);
        c[i] = num;
    }
    
    vector <int> f(m + 1, 0);
    for (int i = 1; i < n; i++){
        if (c[i] > 0)
        f[c[i]]++;
    }
    
    vector <int> p(m + 1, 0);
    for (int i = 1; i <= m; i++){
        p[i] = p[i - 1] + f[i];
    }
    
    for (int k = 1; k <= m; k++){
        int ex = m % k;
        int ans = 0;
        for (int i = 0; ; i++){
            int L = i * k + 1 + ex;
            int R = (i + 1) * k + ex;
            if (L > m) break;
            R = min(R, m);
            
            int count = p[R] - p[L - 1];
            ans += count * (i + 1);
        }
        
        ans += (m / k);
        
        cout << ans << " \n"[k == m];
    }
}

int32_t main() 
{
    auto begin = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // freopen("in",  "r", stdin);
    // freopen("out", "w", stdout);
    
    cin >> t;
    for(int i = 1; i <= t; i++) 
    {
        //cout << "Case #" << i << ": ";
        Solve();
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    // cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
    return 0;
}