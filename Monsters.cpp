#include<bits/stdc++.h>
// #include </Users/nishchay/Desktop/abc.h>
using namespace std;
 
using str =  string;
using ll  =  long long;
using ld  =  long double;
using vl  =  vector<ll>;
using vb  =  vector<bool>;
using vvl  =  vector<vl>;
using vs  =  vector<str>;
using vpl =  vector<pair<ll,ll> >;
using sll =  set<ll>;
using pll =  pair<ll,ll>;
#define mset multiset
 
/*#include<ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using iset = tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>;
#define sAt(s,x) s.find_by_order(x) //Returns xth Iterator
#define sPos(s,x) s.order_of_key(x) //Return lower bound index*/
 
#define pus push_back
#define pub pop_back
#define in  insert
#define ff  first
#define ss  second
 
#define sz(x)     ((ll)(x).size())
#define all(x)    x.begin(),x.end()
#define srt(x)    sort(all(x))
#define srtd(x)   sort(x.rbegin(),x.rend())
#define rev(x)    reverse(all(x));
#define Vmax(x)   *max_element(all(x))
#define Vmin(x)   *min_element(all(x))
#define Vsum(x)   accumulate(all(x),0ll)
#define lowB(v,x) lower_bound(all(v),x)-v.begin()
#define upB(v,x)  upper_bound(all(v),x)-v.begin() 
#define cntB(x)   __builtin_popcountll(x)  
#define cntC(s,x) ll(count(all(s),x))
 
#define For(n)      for (ll i = 0; i < n; i++)
#define ForR(n)     for (ll i = n-1; i >= 0; i--)
#define Forj(n)     for (ll j = 0; j < n; j++)
#define For1(n)     for (ll i = 1; i < n; i++)
#define Forl(x,y,z) for (ll x = y; x < z; x++)
 
#define done     return;
#define nl       cout << "\n";
#define endl     "\n";
#define ya       cout << "YES\n";
#define na       cout << "NO\n";
#define prs(n)   fixed << setprecision(n)
#define dbg(x)   cout << #x << " = " << x << endl;
#define inpt(v)  For(sz(v)) cin >> v[i];
#define prt(v)  {for(auto &x:v) cout << x << ' '; nl}
 
const int M = 1e9+7;
// const int M = 998244353;
const int N = 2e5+5;
const ld pi = 3.141592653589793238;
const ll INF = 1e18;
 
ll power(ll a,ll b){ll r=1; while(b) {if(b&1) r=(r*a)%M; a=(a*a)%M; b/=2;} return r;}
vl sieve(ll n) {vl a(n+1,1),v; a[0]=a[1]=0; Forl(i,2,n+1) if(a[i]) {v.pus(i); for(ll j=i*i; j <=n; j+=i) a[j]=0;} return a;}
vl divsr(ll n) {vl a(n+1,1); For(n+1) a[i]=i; Forl(i,2,n+1) if(a[i]==i) {for(ll j=2*i; j<=n; j+=i) a[j]=i;} return a;}
vl fac(ll n) {vl v(n+1,1); Forl(i,2,n+1) v[i] = (v[i-1]*i)%M; return v;}
ll gcd(ll a, ll b){if(b == 0){return a;}return gcd(b,a%b);}
 
 
/* stuff you should look for 
    * check for int overflow
    * check for time complexity (make sure not to TLE)
    * special case (n = 1)
    * make sure to initialize everything (array)
    * don't be lazy, write out your thought and code it out
*/
 
//-------------------------------------------------------------------------------------------------------------------------------------
void solve(){
    ll n,m;
    vs grid;
    cin >> n >> m;
    For(n) {
        str s;
        cin >> s;
        grid.pus(s);
    }
    vvl lab(n,vl(m,INF));
    vvl labm(n,vl(m,INF));
    queue<vl> q, monsters;
    For(n) {
        Forj(m) {
            if(grid[i][j] == 'M') {
                monsters.push({0,i,j});
            }
            if(grid[i][j] == 'A') {
                q.push({0,i,j});
            }
        }
    }
    
    while(sz(q)) {
        auto cr = q.front();
        q.pop();
        ll crdist = -cr[0], crx = cr[1], cry = cr[2];
        if(lab[crx][cry] <= crdist) continue;
        lab[crx][cry] = crdist;
        ll ndist = crdist+1;
        if(crx+1 < n && grid[crx+1][cry] != '#' && ndist < lab[crx+1][cry]) q.push({-ndist,crx+1,cry});
        if(crx-1 >= 0 && grid[crx-1][cry] != '#' && ndist < lab[crx-1][cry]) q.push({-ndist,crx-1,cry});
        if(cry+1 < m && grid[crx][cry+1] != '#' && ndist < lab[crx][cry+1]) q.push({-ndist,crx,cry+1});
        if(cry-1 >= 0 && grid[crx][cry-1] != '#' && ndist < lab[crx][cry-1]) q.push({-ndist,crx,cry-1});
    }
    
    while(sz(monsters)) {
        auto cr = monsters.front();
        monsters.pop();
        ll crdist = -cr[0], crx = cr[1], cry = cr[2];
        if(labm[crx][cry] <= crdist) continue;
        labm[crx][cry] = crdist;
        ll ndist = crdist+1;
        if(crx+1 < n && grid[crx+1][cry] != '#' && ndist < labm[crx+1][cry]) monsters.push({-ndist,crx+1,cry});
        if(crx-1 >= 0 && grid[crx-1][cry] != '#' && ndist < labm[crx-1][cry]) monsters.push({-ndist,crx-1,cry});
        if(cry+1 < m && grid[crx][cry+1] != '#' && ndist < labm[crx][cry+1]) monsters.push({-ndist,crx,cry+1});
        if(cry-1 >= 0 && grid[crx][cry-1] != '#' && ndist < labm[crx][cry-1]) monsters.push({-ndist,crx,cry-1});
    }
 
    bool found = 0;
    ll lx = -1, ly = -1, st = -1;
    For(n) {
        Forj(m) {
            if(labm[i][j] <= lab[i][j]) lab[i][j] = INF;
            if((i == 0 || i == n-1 || j == 0 || j == m-1) && (lab[i][j] != INF)) {
                found = 1;
                lx = i, ly = j;
            }
            if(found) break;
        }
    }
    if(found) {
        ya
        cout<<lab[lx][ly];nl
        str ans = "";
        while(lab[lx][ly] != 0) {
            if(lx-1 >= 0 && lab[lx-1][ly] == lab[lx][ly]-1) {
                ans += 'D';
                lx = lx-1;
            } else if(lx+1 < n && lab[lx+1][ly] == lab[lx][ly]-1) {
                ans += 'U';
                lx = lx+1;
            } else if(ly-1 >= 0 && lab[lx][ly-1] == lab[lx][ly]-1) {
                ans += 'R';
                ly = ly-1;
            } else if(ly+1 < m && lab[lx][ly+1] == lab[lx][ly]-1) {
                ans += 'L';
                ly = ly+1;
            }
        }
        rev(ans);
        cout<<ans;
        nl
    } else na
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}

